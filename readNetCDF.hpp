

#ifndef readNetCDF__hpp
#define readNetCDF__hpp

#include <rarray>
#include <complex>

/// @brief reads a netcdf file of name filename
/// @brief filename is the name of hte file to be read in
rvector<std::complex<double>> read_NetCDF_file(std::string filename);

#endif
