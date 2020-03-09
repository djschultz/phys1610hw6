#Makefile for gravity_waves.cpp

#Specify what compiler we will use
CXX = g++

#Specify locations of the netcdf libraries
NETCDF_LIB = ${SCINET_NETCDF_ROOT}/lib
NETCDF_INC = ${SCINET_NETCDF_ROOT}/include

#Specify location of hte fftw library
FFTW_LIB = ${SCINET_FFTW_ROOT}/lib
FFTW_INC = ${SCINET_FFTW_ROOT}/include

#Specify location of the openblas library
BLAS_LIB = ${HOME}/OpenBLAS/lib/
BLAS_INC = ${HOME}/OpenBLAS/include/

#Macro for the flags that we will use to compile the code. 
flags = -std=c++14 -O3 -march=native

#Link all of the out files and combine into an executable called antsontable
gravity_waves: gravity_waves.o readNetCDF.o fourier.o power.o correlation.o
	$(CXX) $(flags) -o gravity_waves gravity_waves.o -L$(FFTW_LIB) fourier.o -lfftw3 power.o -L$(BLAS_LIB) correlation.o -lopenblas -L$(NETCDF_LIB) readNetCDF.o -lnetcdf_c++4

#Individually compile all of the modules without making an executable
gravity_waves.o: gravity_waves.cpp 
	$(CXX) $(flags) -c -o gravity_waves.o gravity_waves.cpp

fourier.o: fourier.cpp
	$(CXX) -I$(FFTW_INC) -c -o fourier.o fourier.cpp

power.o: power.cpp
	$(CXX) $(flags) -c -o power.o power.cpp

correlation.o: correlation.cpp
	$(CXX) -I$(BLAS_INC) -c -o correlation.o correlation.cpp

readNetCDF.o: readNetCDF.cpp
	$(CXX) -I$(NETCDF_INC) -c -o readNetCDF.o readNetCDF.cpp

clean: 
	rm -f gravity_waves gravity_waves.o readNetCDF.o fourier.o power.o correlation.o output.dat
	
