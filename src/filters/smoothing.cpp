#include <iostream>
#include "filters/smoothing.h" 
#include <cmath>
#include <numeric>
#include <iomanip>

Smoothing::Smoothing(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
const std::vector<unsigned char> &_red, unsigned int width, unsigned int height ): Filter{_blue, _green, _red, width, height}{


    // doSmoothing(blue); 
    // doSmoothing(green); 
    // doSmoothing(red); 
    
    gaussianBlur(blue);
    gaussianBlur(green);
    gaussianBlur(red);
}

//creating kenrel for smoothing 
double** Smoothing::createKernel(double **input, int size){
    double sigma = 1;
    int W = size;
    double mean = W / 2;
    double sum = 0.0;
    input = new double*[size]{}; 
    for(size_t i{0}; i < size; i++){
        input[i] = new double[size]{}; 
    }
    for (int x = 0; x < W; ++x)
        for (int y = 0; y < W; ++y)
        {
            input[x][y] = exp(-0.5 * (pow((x - mean) / sigma, 2.0) + pow((y - mean) / sigma, 2.0))) / (2 * M_PI * sigma * sigma);
                sum += input[x][y];
        }

    for (int x = 0; x < W; ++x) for (int y = 0; y < W; ++y)
        input[x][y] /= sum;

    return input;
}


// predefined filter 
void Smoothing::doSmoothing(std::vector<unsigned char>& colorVec){
    
    std::vector<double> pushColorVect;

    for(int i{0}; i < colorVec.size(); i++){
        pushColorVect.push_back(colorVec[i]); 
    }
    

    for (int v{1}; v < (hgt-2)*3; v++){
        for (int u{1}; u < (wdt-2)*3; u++){
            double sum = 0; 
            for(int j{-1}; j < 2; j++){
                for(int i{-1}; i< 2; i++){ 
                    int p = pushColorVect[((v+j)*wdt+(u+i))];
                    double c = mask[j+1][i+1]; 
                    sum += c * p; 
                }
            }
            colorVec[(v*wdt + u)] = round(sum); //or 
        }
    }
}

void Smoothing::gaussianBlur(std::vector<unsigned char>& colorVec){

    //calculate padding size and kernel size 
    size_t pad_rows = (hgt)/2+1; 
    size_t pad_cols = (wdt)/2+1; 
    constexpr int kernelDim{3}; 

    
    double **gusM;
    gusM = createKernel(gusM, kernelDim);
   

    //create padded matrix
    std::vector<unsigned char> tmp1((wdt + (2 * pad_cols)), 0);
    std::vector<std::vector<unsigned char>> paddedImg((hgt + (2 * pad_rows)), tmp1);

    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt); i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt); j++){
            paddedImg[i][j] = colorVec[k];
            k++;                     
        }
    }


    //create copy of padded matrix
    std::vector<unsigned char> tmp((wdt + (2 * pad_cols)), 0);
    std::vector<std::vector<unsigned char>> paddedImgCopy((hgt + (2 * pad_rows)), tmp);


    for(size_t i{0}; i < (hgt+(2*pad_rows)); i++ ){
        for(size_t j{0}; j< (wdt+(2*pad_cols)); j++){
            paddedImgCopy[i][j] = paddedImg[i][j];      
        }
    }
    


    for(size_t v{pad_rows}; v < (pad_rows + hgt); v++ ){
        for(size_t u{pad_cols}; u < (pad_cols + wdt); u++){
            std::vector<double> matrix;
            for(int x{-1}; x < kernelDim-1; x++){
                for(int y{-1}; y < kernelDim-1; y++){
                    matrix.push_back(static_cast<double>(paddedImgCopy[v+x][u+y]) * gusM[x+1][y+1]); 
                }
            } 
            double sum{0};    
            for(auto x: matrix){
                sum+=x;
            }
            paddedImgCopy[v][u] = std::round(sum); 

        }

    }

    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt); i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt); j++){
            colorVec[k] = paddedImgCopy[i][j]; 
            k++; 
        }     
    }

    for(int i{}; i<kernelDim; ++i){
        delete[] gusM[i];
    }
    delete[] gusM;

}; 

