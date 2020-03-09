

#ifndef CORRELATION__HPP
#define CORRELATION__HPP

#include <rarray>
#include <complex>

/// @brief function to calculate the correlation between two power spectra
/// @param vecLength the length of the vectors whose correlation we're calculating
/// @param signal1 one of the vectors
/// @param signal2 the other vector
double corr(int vecLength, rvector<double> signal1, rvector<double> signal2);

#endif
