
#ifndef POWER__HPP
#define POWER__HPP


#include <rarray>
#include <complex>

/// @brief calculates the power spectrum of a signal, given its fourier transform
/// @param fhat is the fourier transform of some signal
/// @param spectrum is power spectrum of fhat
void power_spectrum(rvector<std::complex<double>> fhat, rvector<double> spectrum);

#endif
