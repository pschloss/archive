// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// archive_metadata
Rcpp::List archive_metadata(const std::string& path);
RcppExport SEXP _archive_archive_metadata(SEXP pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type path(pathSEXP);
    rcpp_result_gen = Rcpp::wrap(archive_metadata(path));
    return rcpp_result_gen;
END_RCPP
}
// archive_filters
Rcpp::IntegerVector archive_filters();
RcppExport SEXP _archive_archive_filters() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(archive_filters());
    return rcpp_result_gen;
END_RCPP
}
// archive_formats
Rcpp::IntegerVector archive_formats();
RcppExport SEXP _archive_archive_formats() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(archive_formats());
    return rcpp_result_gen;
END_RCPP
}
// libarchive_version
std::string libarchive_version();
RcppExport SEXP _archive_libarchive_version() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(libarchive_version());
    return rcpp_result_gen;
END_RCPP
}
// archive_extract_
void archive_extract_(const std::string& archive_filename, size_t sz);
RcppExport SEXP _archive_archive_extract_(SEXP archive_filenameSEXP, SEXP szSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type archive_filename(archive_filenameSEXP);
    Rcpp::traits::input_parameter< size_t >::type sz(szSEXP);
    archive_extract_(archive_filename, sz);
    return R_NilValue;
END_RCPP
}
// read_file_connection
SEXP read_file_connection(const std::string& filename, const std::string& mode, size_t sz);
RcppExport SEXP _archive_read_file_connection(SEXP filenameSEXP, SEXP modeSEXP, SEXP szSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type mode(modeSEXP);
    Rcpp::traits::input_parameter< size_t >::type sz(szSEXP);
    rcpp_result_gen = Rcpp::wrap(read_file_connection(filename, mode, sz));
    return rcpp_result_gen;
END_RCPP
}
// read_connection
SEXP read_connection(const std::string& archive_filename, const std::string& filename, const std::string& mode, int format, Rcpp::NumericVector filters, size_t sz);
RcppExport SEXP _archive_read_connection(SEXP archive_filenameSEXP, SEXP filenameSEXP, SEXP modeSEXP, SEXP formatSEXP, SEXP filtersSEXP, SEXP szSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type archive_filename(archive_filenameSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type mode(modeSEXP);
    Rcpp::traits::input_parameter< int >::type format(formatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type filters(filtersSEXP);
    Rcpp::traits::input_parameter< size_t >::type sz(szSEXP);
    rcpp_result_gen = Rcpp::wrap(read_connection(archive_filename, filename, mode, format, filters, sz));
    return rcpp_result_gen;
END_RCPP
}
// write_file_connection
SEXP write_file_connection(const std::string& filename, Rcpp::NumericVector filters);
RcppExport SEXP _archive_write_file_connection(SEXP filenameSEXP, SEXP filtersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type filters(filtersSEXP);
    rcpp_result_gen = Rcpp::wrap(write_file_connection(filename, filters));
    return rcpp_result_gen;
END_RCPP
}
// write_files_
SEXP write_files_(const std::string& archive_filename, Rcpp::CharacterVector files, int format, Rcpp::NumericVector filters, size_t sz);
RcppExport SEXP _archive_write_files_(SEXP archive_filenameSEXP, SEXP filesSEXP, SEXP formatSEXP, SEXP filtersSEXP, SEXP szSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type archive_filename(archive_filenameSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type files(filesSEXP);
    Rcpp::traits::input_parameter< int >::type format(formatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type filters(filtersSEXP);
    Rcpp::traits::input_parameter< size_t >::type sz(szSEXP);
    rcpp_result_gen = Rcpp::wrap(write_files_(archive_filename, files, format, filters, sz));
    return rcpp_result_gen;
END_RCPP
}
// write_connection
SEXP write_connection(const std::string& archive_filename, const std::string& filename, int format, Rcpp::NumericVector filters, size_t sz);
RcppExport SEXP _archive_write_connection(SEXP archive_filenameSEXP, SEXP filenameSEXP, SEXP formatSEXP, SEXP filtersSEXP, SEXP szSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type archive_filename(archive_filenameSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type format(formatSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type filters(filtersSEXP);
    Rcpp::traits::input_parameter< size_t >::type sz(szSEXP);
    rcpp_result_gen = Rcpp::wrap(write_connection(archive_filename, filename, format, filters, sz));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_archive_archive_metadata", (DL_FUNC) &_archive_archive_metadata, 1},
    {"_archive_archive_filters", (DL_FUNC) &_archive_archive_filters, 0},
    {"_archive_archive_formats", (DL_FUNC) &_archive_archive_formats, 0},
    {"_archive_libarchive_version", (DL_FUNC) &_archive_libarchive_version, 0},
    {"_archive_archive_extract_", (DL_FUNC) &_archive_archive_extract_, 2},
    {"_archive_read_file_connection", (DL_FUNC) &_archive_read_file_connection, 3},
    {"_archive_read_connection", (DL_FUNC) &_archive_read_connection, 6},
    {"_archive_write_file_connection", (DL_FUNC) &_archive_write_file_connection, 2},
    {"_archive_write_files_", (DL_FUNC) &_archive_write_files_, 5},
    {"_archive_write_connection", (DL_FUNC) &_archive_write_connection, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_archive(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
