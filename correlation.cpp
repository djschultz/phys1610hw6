#include <iostream>
#include <rarray>
#include <complex>
#include <cblas.h>

double corr(int vecLength, rvector<double> signal1, rvector <double> signal2){
    return cblas_ddot(vecLength, signal1, 1, signal2, 1)/sqrt(cblas_ddot(vecLength, signal1, 1, signal1, 1)*cblas_ddot(vecLength, signal2, 1, signal2, 1));
}

