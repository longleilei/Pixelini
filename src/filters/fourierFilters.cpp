#include <iostream>
#include "filters/fourierFilters.h" 
#include <cmath>
#include <numeric>
#include <iomanip>

FourierFilters::FourierFilters(const std::vector<std::vector<Complex>>& _dftMatrix, unsigned int width, unsigned int height )
    :dftMatrix{_dftMatrix}{

    // std::cout << " hello from const " << std::endl;

    // for (int i{}; i < width; i++){
    //     for (int j{}; j < height; j++){
    //         std::cout << dftMatrix[i][j] << " "; 
    //     }
    //     std::cout << std::endl;
    // }

    threshold = 0.5; 
    M = width; 
    L = height; 
    length = M > L ? M : L; 

}




std::vector<std::vector<double>> FourierFilters::generateFilter(int M, double threshold){

    std::vector<double> tmp2(M, 0); 
    std::vector<std::vector<double>> distanceMatrix(M, tmp2);

    for(int i{}; i < M; i++){
        for(int j{}; j < M; j++ ){
            distanceMatrix[i][j] = sqrt(pow(i - M/2, 2) + pow(j - M/2, 2)); 
        }
    }

 

    std::vector<double> tmp3(M, 0); 
    std::vector<std::vector<double>> distanceMatrixAfterThreshold(M, tmp3);

    for(int i{}; i < M; i++){
        for(int j{}; j < M; j++ ){
            if (distanceMatrix[i][j] > threshold){
                distanceMatrixAfterThreshold[i][j] = 1; 
                continue;
            } 
            distanceMatrixAfterThreshold[i][j] = 0; 
        }
    }

    return distanceMatrixAfterThreshold; 
}

std::vector<std::vector<double>> FourierFilters::generateGaussFilter(int M, double threshold){

    std::vector<double> tmp2(M, 1); 
    std::vector<std::vector<double>> distanceMatrix(M, tmp2);

    for(int i{}; i < M; i++){
        for(int j{}; j < M; j++ ){
            distanceMatrix[i][j] = sqrt(pow(i - M/2, 2) + pow(j - M/2, 2)); 
        }
    }


    std::vector<double> tmp3(M, 0); 
    std::vector<std::vector<double>> distanceMatrixAfterThreshold(M, tmp3);

    for(int i{}; i < M; i++){
        for(int j{}; j < M; j++ ){
            distanceMatrixAfterThreshold[i][j] = exp(-((distanceMatrix[i][j] * distanceMatrix[i][j])/(2*threshold*threshold))); 
        }
    }

    return distanceMatrixAfterThreshold; 
}

std::vector<std::vector<double>> FourierFilters::generateButterworthFilter(int M){
    std::vector<double> tmp2(M, 0); 
    std::vector<std::vector<double>> distanceMatrix(M, tmp2);

    for(int i{}; i < M; i++){
        for(int j{}; j < M; j++ ){
            distanceMatrix[i][j] = sqrt(i*i + j*j); 
        }
    }

    std::vector<double> tmp3(M, 0); 
    std::vector<std::vector<double>> filter(M, tmp3);
    int Do{15}; 
    int n{5}; 

    for(int i{}; i < M; i++){
        for(int j{}; j < M; j++ ){
            filter[i][j] = 1 / (1 + pow((distanceMatrix[i][j]/Do), 2*n)); 
        }
    }

    return filter; 
}

void FourierFilters::printMatrixComplex(std::vector<std::vector<Complex>> matrix, int length){
    for (int rows{0}; rows < length; ++rows) {
        for (int cols{0}; cols < length; ++cols) {
            std::cout << std::setw(10) << matrix[rows][cols] << " "; 
        }
        std::cout << std::endl; 
    }
}

void FourierFilters::printMatrixDouble(std::vector<std::vector<double>> matrix, int length){
    for (int rows{0}; rows < length; ++rows) {
        for (int cols{0}; cols < length; ++cols) {
            std::cout << std::setw(10) << matrix[rows][cols] << " "; 
        }
        std::cout << std::endl; 
    }
}

 std::vector<std::vector<Complex>> FourierFilters::filterMatrix(){
 
    /* Filter generation */  
    
    auto filterKernel = generateButterworthFilter(length); 


    //std::cout << "printing a filter" << std::endl; 
    //printMatrixDouble(filterKernel, length); 


    /*Pixel by pixel filtration */ 
    std::vector<Complex> tmp4(length, {1,0});
    std::vector<std::vector<Complex>> filteredMatrix(length, tmp4);

    //std::cout << "printing dft matrix" << std::endl; 
    //printMatrixComplex(dftMatrix, length); 

    for(int i{}; i < length; i++){
        for(int j{}; j < length; j++ ){
    
            filteredMatrix[i][j] = dftMatrix[i][j] * filterKernel[i][j]; 
            // std::cout << "dftMatrix[i][j] " << dftMatrix[i][j] << " filterKernel[i][j] " << filterKernel[i][j] << " filteredMatrix[i][j] " << filteredMatrix[i][j]; 
            std::cout << dftMatrix[i][j] << " "; 

        } 
        //std::cout << std::endl;
    }

    std::cout << "printing filtered matrix" << std::endl; 
    printMatrixComplex(filteredMatrix, length); 


    return filteredMatrix; 


}