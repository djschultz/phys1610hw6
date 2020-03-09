
#include <complex>
#include <rarray>
#include <fftw3.h>

typedef std::complex<double> complex;



void fft_fast(const rvector<complex>& f, rvector<complex>& fhat, bool inverse){
    int n = f.size(); // length of the vector to be transformed
    fftw_plan p = fftw_plan_dft_1d(n, (fftw_complex*)f.data(), (fftw_complex*)fhat.data(), inverse?FFTW_BACKWARD:FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
}
