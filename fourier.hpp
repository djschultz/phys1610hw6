

#ifndef FOURIER__HPP
#define FOURIER__HPP

#include <complex>
#include <rarray>

typedef std::complex<double> complex;

void fft_fast(const rvector<complex>& f, rvector<complex>& fhat, bool inverse);


#endif
