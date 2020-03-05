
#include <rarray>
#include <complex>

#include "power.hpp"

void powerSpectrum(rvector<std::complex<double>> fhat, rvector<double> spectrum){
    for(int i = 0; i < fhat.size(); i++){
        spectrum[i] = norm(fhat[i]);
    }
}
