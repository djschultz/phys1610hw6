#include <iostream>
#include <rarray>
#include <rarrayio>
#include <complex>
#include <fftw3.h>
#include "readNetCDF.hpp"


int main(int argc, const char * argv[]){
    
    rvector<std::complex<double>> prediction = read_NetCDF_file("gwdata/GWprediction.nc");
    rvector<std::complex<double>> detection = read_NetCDF_file("gwdata/detection01.nc");
    
    

    return 0;
}
