#include "r_archive.h"
#include <fcntl.h>
#include <string.h>
#include <vector>

/* callback function to store received data */
static size_t rchive_write_zip_data(
    const void* contents, size_t sz, size_t n, Rconnection ctx) {
  rchive* r = (rchive*)ctx->private_ptr;

  size_t realsize = sz * n;
  archive_write_data(r->ar, contents, realsize);
  r->size += realsize;

  return n;
}

static Rboolean rchive_write_zip_open(Rconnection con) {
  rchive* r = (rchive*)con->private_ptr;

  r->ar = archive_write_new();

  for (int i = 0; i < FILTER_MAX && r->filters[i] != -1; ++i) {
    r->last_response = archive_write_add_filter(r->ar, r->filters[i]);
    if (r->last_response != ARCHIVE_OK) {
      Rf_error(archive_error_string(r->ar));
    }
  }

  r->last_response = archive_write_set_format_zip(r->ar);

  if (!r->options.empty()) {
    r->last_response = archive_write_set_options(r->ar, r->options.c_str());
    if (r->last_response != ARCHIVE_OK) {
      con->isopen = FALSE;
      Rf_error(archive_error_string(r->ar));
    }
  }

  r->last_response =
      archive_write_open_filename(r->ar, r->archive_filename.c_str());
  if (r->last_response != ARCHIVE_OK) {
    con->isopen = FALSE;
    Rf_error(archive_error_string(r->ar));
  }

  r->entry = archive_entry_new();

  archive_entry_set_pathname(r->entry, r->filename.c_str());
  archive_entry_set_filetype(r->entry, AE_IFREG);
  archive_entry_set_perm(r->entry, 0644);
  archive_entry_unset_size(r->entry);
  archive_write_header(r->ar, r->entry);

  archive_entry_free(r->entry);

  con->isopen = TRUE;
  return TRUE;
}

/* This function closes the temporary scratch file, then writes the actual
 * archive file based on the archive filename given and then unlinks the
 * scratch file */
void rchive_write_zip_close(Rconnection con) {
  rchive* r = (rchive*)con->private_ptr;

  if (!con->isopen) {
    return;
  }
  /* Close scratch file */
  archive_write_close(r->ar);
  archive_write_free(r->ar);

  con->isopen = FALSE;
}

void rchive_write_zip_destroy(Rconnection con) {
  rchive* r = (rchive*)con->private_ptr;

  /* free the handle connection */
  delete r;
}

// This writes a single (zip) file to a new connection. Unlike other archive
// formats zip does not need to know the size of the file up front.
// This lets us write to it without having to write to a scratch file first.
[[cpp11::register]] SEXP archive_write_zip_(
    const std::string& archive_filename,
    const std::string& filename,
    cpp11::integers filters,
    cpp11::strings options,
    size_t sz) {
  Rconnection con;
  SEXP rc = PROTECT(new_connection("input", "wb", "archive_write", &con));

  /* Setup archive */
  rchive* r = (rchive*)new rchive;

  r->archive_filename = std::move(archive_filename);

  // Initialize filters
  if (filters.size() > FILTER_MAX) {
    cpp11::stop("Cannot use more than %i filters", FILTER_MAX);
  }
  for (int i = 0; i < FILTER_MAX; ++i) {
    r->filters[i] = -1;
  }
  for (int i = 0; i < filters.size(); ++i) {
    r->filters[i] = filters[i];
  }

  r->filename = std::move(filename);

  if (options.size() > 0) {
    r->options = options[0];
  }

  /* set connection properties */
  con->incomplete = TRUE;
  con->private_ptr = r;
  con->canread = FALSE;
  con->canseek = FALSE;
  con->canwrite = TRUE;
  con->isopen = FALSE;
  con->blocking = TRUE;
  con->text = FALSE;
  con->open = rchive_write_zip_open;
  con->close = rchive_write_zip_close;
  con->destroy = rchive_write_zip_destroy;
  con->write = rchive_write_zip_data;

  UNPROTECT(1);
  return rc;
}