#include <iostream>
#include <rarray>
#include <rarrayio>
#include <complex>
#include <fftw3.h>
#include "readNetCDF.hpp"
#include "fourier.hpp"
#include "power.hpp"

int main(int argc, const char * argv[]){
    
    rvector<std::complex<double>> prediction = read_NetCDF_file("gwdata/GWprediction.nc");
    rvector<std::complex<double>> detection = read_NetCDF_file("gwdata/detection01.nc");
    
    int dataLength = prediction.size();
    rvector<std::complex<double>> predictionHat(dataLength); 
    rvector<std::complex<double>> detectionHat(dataLength);
    fft_fast(prediction, predictionHat, 0);
    fft_fast(detection, detectionHat, 0);
    
    

    return 0;
}
