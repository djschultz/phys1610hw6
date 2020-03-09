#include <iostream>
#include <rarray>
#include <complex>
#include <cblas.h>

/// @brief function to calculate the correlation between two power spectra
/// @param vecLength the length of the vectors whose correlation we're calculating
/// @param signal1 one of the vectors
/// @param signal2 the other vector
double corr(int vecLength, rvector<double> signal1, rvector <double> signal2){
    return cblas_ddot(vecLength, signal1, 1, signal2, 1)/sqrt(cblas_ddot(vecLength, signal1, 1, signal1, 1)*cblas_ddot(vecLength, signal2, 1, signal2, 1));
}

