#include "filters/fourier.h"
#include <cmath>
#include<vector> 
#include <iomanip>


Fourier::Fourier(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height): Filter{_blue, _green, _red, width, height}{

    M = wdt; 
    L = hgt; 
    length = M > L ? M : L; 

    for(int m{0}; m < blue.size(); m++){
        std::cout << (short) blue[m] << " ";       
    }
    std::cout << std::endl; 
};

std::vector<std::vector<Complex>> Fourier::createDFT(size_t M) {
    std::vector<Complex> tmp(M, {1,0});
    std::vector < std::vector<Complex>> resultMatrix(M, tmp);
    for (int rows{1}; rows < M; ++rows) {
        for (int cols{1}; cols < M; ++cols) {
            Complex compl1{ cos(2 * M_PI / M), -sin(2*M_PI/M)};
            resultMatrix[rows][cols] = compl1 ^ (rows * cols);
        }
    }
    return resultMatrix; 
}


std::vector<std::vector<Complex>> Fourier::createIDFT(size_t M) {
    std::vector<Complex> tmp(M, {1,0});
    std::vector < std::vector<Complex>> resultMatrix(M, tmp);
    for (int rows{1}; rows < M; ++rows) {
        for (int cols{1}; cols < M; ++cols) {
            Complex compl1{ cos(2 * M_PI / M), sin(2*M_PI/M) };
            resultMatrix[rows][cols] = (compl1 ^ (rows * cols));
        }
    }

    std::vector<Complex> tmp2(M, {1,0});
    std::vector < std::vector<Complex>> resultMatrixDivided(M, tmp2);
    for (int rows{0}; rows < M; ++rows) {
        for (int cols{0}; cols < M; ++cols) {
            resultMatrixDivided[rows][cols] = resultMatrix[rows][cols]; 
        }
    }
    return resultMatrixDivided; 
}

std::vector<std::vector<Complex>> Fourier::matrixMult(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<unsigned char>> matrixB, size_t M){
    Complex complexSum{0, 0};
    std::vector<Complex> tmp(M, {0,0});
    std::vector < std::vector<Complex>> resultMatrix(M, tmp);
    for(int m{0}; m < M; m++){
        for(int i{0}; i < M; i++){ 
            for(int j{0}; j < M; j++){      
                complexSum = complexSum + matrixA[i][j] * Complex(matrixB[j][m], 0);      
            }
            resultMatrix[i][m] = complexSum;
            complexSum = {0,0};  
        }
    }
    return resultMatrix; 
}

std::vector<std::vector<Complex>> Fourier::matrixMult2(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<Complex>> matrixB, size_t M){
    Complex complexSum{0, 0};
    std::vector<Complex> tmp(M, {1,0});
    std::vector < std::vector<Complex>> resultMatrix(M, tmp);
    for(int m{0}; m < M; m++){
        for(int i{0}; i < M; i++){ 
            for(int j{0}; j < M; j++){      
                complexSum = complexSum + matrixA[i][j] * matrixB[j][m];      
            }
            resultMatrix[i][m] = complexSum;
            complexSum = {0,0};  
        }
    }
    return resultMatrix; 
}

std::vector<std::vector<Complex>> Fourier::matrixMultFinal(std::vector<std::vector<Complex>> matrixA, std::vector<std::vector<Complex>> matrixB, size_t M){
    Complex complexSum{0, 0};
    std::vector<Complex> tmp(M, {0,0});
    std::vector <std::vector<Complex>> resultMatrix(M, tmp);
    for(int m{0}; m < M; m++){
        for(int i{0}; i < M; i++){ 
            for(int j{0}; j < M; j++){      
                complexSum = complexSum + matrixA[i][j] * matrixB[j][m];      
            }
            resultMatrix[i][m] = complexSum;
            complexSum = {0,0};  
        }
    }
    return resultMatrix; 
}

void Fourier::printMatrixComplex(std::vector<std::vector<Complex>> matrix, size_t length){
    for (int rows{0}; rows < length; ++rows) {
        for (int cols{0}; cols < length; ++cols) {
            std::cout << std::setw(10) << std::setprecision(2) << std::fixed << matrix[rows][cols] << " "; 
        }
        std::cout << std::endl; 
    }
}

void Fourier::printMatrixDouble(std::vector<std::vector<double>> matrix, size_t length){
    for (int rows{0}; rows < length; ++rows) {
        for (int cols{0}; cols < length; ++cols) {
            std::cout << std::setw(10) << matrix[rows][cols] << " "; 
        }
        std::cout << std::endl; 
    }
}






std::vector<std::vector<Complex>> Fourier::createSignal(const std::vector<unsigned char>& pixelVect){

    
    std::vector<unsigned char> tmp1(length, 0); 
    std::vector<std::vector<unsigned char>> pixelMatrix(length, tmp1);

    for(int i{}, k{}; i < M; i++){
        for(int j{}; j < L; j++ ){
            pixelMatrix[i][j] = pixelVect[k]; 
            k++; 
        }   
    }


    /* Create DFT Matrix */ 
    auto dftMatrix = createDFT(length); 

    /* Result1 is multiplying DFT matrix with centered matrix */  
    auto result1 = matrixMult(dftMatrix, pixelMatrix, length); 

    /* Result2 is multiplying result1 with dft again */  
    auto result2 = matrixMult2(result1, dftMatrix, length); 

    //printMatrixComplex(result2, length); 


    return result2; 


}

std::vector<unsigned char> Fourier::returnPixels(const std::vector<std::vector<Complex>>& complexVector){
    
    auto idftMonster = createIDFT(length); 

    auto result5 = matrixMult2(idftMonster, complexVector, length); 
    auto resultFinal =  matrixMultFinal(result5, idftMonster, length);

    for(int i{0}; i < length; i++){
        for(int j{0}; j < length; j++){
            resultFinal[i][j] = resultFinal[i][j] / (length*length); 
        }
    }

    //printMatrixComplex(resultFinal, length); 

    std::vector<unsigned char> result; 

    for(int i{}; i < M; i++){
        for(int j{}; j < L; j++ ){
            result.push_back(resultFinal[i][j].getReal()); 
        }   
    }

    // std::cout << "printing matrix after idft" << std::endl; 
    // for(int m{0}; m < blue.size(); m++){
    //     std::cout << (short) result[m] << " ";       
    // }
    // std::cout << std::endl; 

    return result; 

    

}


