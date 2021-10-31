#pragma once
#include <vector>
#include "filters/filter.h"
#include "utility/complex.h"

class FourierFilters
{   
    std::vector<std::vector<Complex>> dftBlue; 
    std::vector<std::vector<Complex>> dftGreen;
    std::vector<std::vector<Complex>> dftRed;
    size_t M{}; 
    size_t L{}; 
    size_t length{}; 
    size_t threshold{}; 



public:
    FourierFilters(const std::vector<std::vector<Complex>> &dftBlue, 
    const std::vector<std::vector<Complex>> &dftGreen, const std::vector<std::vector<Complex>> &dftRed, 
    unsigned int width, unsigned int height);

    std::vector<std::vector<Complex>> matrixMult(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<int>> matrixB, int M); 
    std::vector<std::vector<Complex>> matrixMult2(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<Complex>> matrixB, int M); 
    std::vector<std::vector<Complex>> matrixMultFinal(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<Complex>> matrixB, int M); 

    double calculateThreshold(std::vector<std::vector<Complex>> pixelMatrix); 

    std::vector<std::vector<double>> generateFilter(int M, double threshold); 
    std::vector<std::vector<double>> generateGaussFilter(int M, double threshold); 
    std::vector<std::vector<double>> generateButterworthFilter(int M);  

    void printMatrixDouble(std::vector<std::vector<double>> matrix, int length); 
    void printMatrixComplex(std::vector<std::vector<Complex>> matrix, int length); 

    std::vector<std::vector<Complex>> filterMatrix(std::vector<std::vector<Complex>>& dftMatrix);

    std::vector<std::vector<Complex>> getcomplBlue(); 
    std::vector<std::vector<Complex>> getcomplGreen(); 
    std::vector<std::vector<Complex>> getcomplRed(); 


};