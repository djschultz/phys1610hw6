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
    rvector<std::complex<double>> prediction = read_NetCDF_file("gwdata/GWprediction.nc"); // read in the prediction file
    int numDataSets = 32; // We have 32 data measurements
    int dataLength = prediction.size(); 
    rvector<std::complex<double>> predictionHat(dataLength);
    fft_fast(prediction, predictionHat, 0); // fourier transform the prediction, and store in predictionHat
    rvector<double> predictionSpectrum(dataLength);
    power_spectrum(predictionHat, predictionSpectrum); // calculate the power spectrum of the prediction and store it in predictionSpectrum
    
    for(int i = 1; i <= numDataSets; i++){ // loop through all datasets
        std::string filenum = std::string(std::max(1-i/10,0), '0').append(std::to_string(i)); // generate a string which is the number of the file
        std::string filename = "gwdata/detection" +  filenum + ".nc";  // take the number and combine it into hte full filename
        rvector<std::complex<double>> detection = read_NetCDF_file(filename); // read in the data
        rvector<std::complex<double>> detectionHat(dataLength); 
        fft_fast(detection, detectionHat, 0); // take the fourier transform of the data
        rvector<double> detectionSpectrum(dataLength);    
        power_spectrum(detectionHat, detectionSpectrum); // calculat the power spectrum of the detection and store it in detectionSpectrum
        std::cout << "dataset: "<< i << ", correlation: " << corr(dataLength, predictionSpectrum, detectionSpectrum) << std::endl; // print out the correlation coefficient between the data and prediction
    }

    return 0;
}
