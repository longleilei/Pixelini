#pragma once 
#include "filters/filter.h"
#include <vector> 
#include "utility/complex.h"

class Fourier: public Filter {

    size_t M{}; 
    size_t L{}; 
    size_t length{}; 

public: 

    Fourier(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height); 

    std::vector<std::vector<Complex>> createDFT(size_t M); 
    std::vector<std::vector<Complex>> createIDFT(size_t M);

    std::vector<std::vector<Complex>> matrixMult(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<unsigned char>> matrixB, size_t M); 
    std::vector<std::vector<Complex>> matrixMult2(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<Complex>> matrixB, size_t M); 
    std::vector<std::vector<Complex>> matrixMultFinal(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<Complex>> matrixB, size_t M); 

    void printMatrixDouble(std::vector<std::vector<double>> matrix, size_t length); 
    void printMatrixComplex(std::vector<std::vector<Complex>> matrix, size_t length);

    std::vector<std::vector<Complex>> createSignal(const std::vector<unsigned char>& pixelVect); 
    std::vector<unsigned char> returnPixels(const std::vector<std::vector<Complex>>& complexVector); 
    



}; 


 