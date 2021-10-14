#pragma once 
#include "filters/filter.h"
#include <vector> 
#include "utility/complex.h"


class FFT: public Filter {

    size_t M{}; 
    size_t L{}; 
    size_t length{}; 

public: 
    FFT(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height); 
    std::vector<Complex> fft(std::vector<unsigned  char>& img); 
    void fftRec(std::vector<Complex>& complexVec, int n);
    std::vector<unsigned char> ifft(std::vector<Complex>& complexVec); 
    void ifftRec(std::vector<Complex>& complexVec, int n); 

}; 
