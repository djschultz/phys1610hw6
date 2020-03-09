

#ifndef FOURIER__HPP
#define FOURIER__HPP

#include <complex>
#include <rarray>

typedef std::complex<double> complex;

/// @brief performs the fast fourier transform of a vector and stores it in fhat
/// @param f is the function to be fourier transformed
/// @param fhat is the result of the fourier transform
/// @param inverse is whether or not we are doing the forward or inverse trasnform. 0 is forward, 1 is inverse
void fft_fast(const rvector<complex>& f, rvector<complex>& fhat, bool inverse);


#endif
