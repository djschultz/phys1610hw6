#include <iostream>
#include <rarray>
#include <rarrayio>
#include <complex>
#include <fftw3.h>
#include "readNetCDF.hpp"
#include "fourier.hpp"
#include "power.hpp"
#include "correlation.hpp"

int main(int argc, const char * argv[]){
    
    rvector<std::complex<double>> prediction = read_NetCDF_file("gwdata/GWprediction.nc");
    int numDataSets = 32;
    int dataLength = prediction.size();
    rvector<std::complex<double>> predictionHat(dataLength);
    fft_fast(prediction, predictionHat, 0);
    rvector<double> predictionSpectrum(dataLength);
    power_spectrum(predictionHat, predictionSpectrum);
    
    for(int i = 1; i <= numDataSets; i++){
        std::string filenum = std::string(std::max(1-i/10,0), '0').append(std::to_string(i));
        std::string filename = "gwdata/detection" +  filenum + ".nc"; 
        rvector<std::complex<double>> detection = read_NetCDF_file(filename); 
        rvector<std::complex<double>> detectionHat(dataLength);
        fft_fast(detection, detectionHat, 0);
        rvector<double> detectionSpectrum(dataLength);    
        power_spectrum(detectionHat, detectionSpectrum);
        std::cout << "dataset: "<< i << ", correlation: " << corr(dataLength, predictionSpectrum, detectionSpectrum) << std::endl; 
    }

    return 0;
}
