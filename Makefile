#Makefile for antsontable.cpp

#Specify what compiler we will use
CXX = g++

#Specify locations of the netcdf libraries
NETCDF_LIB = ${SCINET_NETCDF_ROOT}/lib
NETCDF_INC = ${SCINET_NETCDF_ROOT}/include

FFTW_LIB = ${SCINET_FFTW_ROOT}/lib
FFTW_INC = ${SCINET_FFTW_ROOT}/include

#Macro for the flags that we will use to compile the code. 
flags = -std=c++14 -O3 -march=native

#Link all of the out files and combine into an executable called antsontable
gravity_waves: gravity_waves.o readNetCDF.o fourier.o power.o
#ants.o partition.o vectorization.o timeEvolve.o report.o writeText.o writeBinary.o writeNetCDF.o
	$(CXX) $(flags) -o gravity_waves gravity_waves.o -L$(FFTW_LIB) fourier.o -lfftw3 power.o -L$(NETCDF_LIB) readNetCDF.o -lnetcdf_c++4

#Individually compile all of the modules without making an executable
gravity_waves.o: gravity_waves.cpp 
#ants.hpp partition.hpp vectorization.hpp timeEvolve.hpp report.hpp
	$(CXX) $(flags) -c -o gravity_waves.o gravity_waves.cpp

fourier.o: fourier.cpp
	$(CXX) -I$(FFTW_INC) -c -o fourier.o fourier.cpp

power.o: power.cpp
	$(CXX) $(flags) -c -o power.o power.cpp

readNetCDF.o: readNetCDF.cpp
	$(CXX) -I$(NETCDF_INC) -c -o readNetCDF.o readNetCDF.cpp

clean: 
	rm -f gravity_waves gravity_waves.o readNetCDF.o fourier.o power.o vectorization.o timeEvolve.o report.o output.dat writeText.o writeBinary.o writeNetCDF.o readText.o readBinary.o readNetCDF.o file_reading.o ants.rat ants.bin ants.nc
	
