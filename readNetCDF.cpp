#include <rarray>
#include <netcdf>
#include <complex>

#include "readNetCDF.hpp"

rvector<std::complex<double>> read_NetCDF_file(std::string filename){
    netCDF::NcFile ncfile(filename, netCDF::NcFile::read);
    rvector<std::complex<double>> f(ncfile.getDim("nt").getSize());
    ncfile.getVar("f").getVar(f.data());
    
    return f;
}
