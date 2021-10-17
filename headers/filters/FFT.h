#pragma once 
#include "filters/filter.h"
#include <vector> 
#include "utility/complex.h"


class FFT: public Filter {

    size_t M{}; 
    size_t L{}; 
    size_t length{}; 

    std::vector<Complex> complBlue; 
    std::vector<Complex> complGreen; 
    std::vector<Complex> complRed; 

public: 
    FFT(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height); 
    std::vector<Complex> fft(std::vector<unsigned  char>& img); 
    void fftRec(std::vector<Complex>& complexVec, int n);
    std::vector<unsigned char> ifft(std::vector<Complex>& complexVec); 
    void ifftRec(std::vector<Complex>& complexVec, int n); 
    std::vector<std::vector<Complex>> createMatrixFromVector(std::vector<Complex> colorVec); 
    std::vector<Complex> createVectorFromMatrix(std::vector<std::vector<Complex>> colorMat); 
    void setVectors(std::vector<unsigned char> blue, std::vector<unsigned char> green, std::vector<unsigned char> red); 
    std::vector<Complex> getcomplBlue(); 
    std::vector<Complex> getcomplGreen(); 
    std::vector<Complex> getcomplRed(); 

    void reverseVectors(); 


}; 
