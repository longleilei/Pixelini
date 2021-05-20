#include <iostream>
#include "filters/smoothing.h" 
#include <cmath>
#include <numeric>
#include <iomanip>

Smoothing::Smoothing(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, const std::vector<unsigned char> &_red, unsigned int width, unsigned int height ): wdt{width}, hgt{height}{


    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));
    std::cout << "width: " << wdt << " heidht: " <<hgt << "\n";
    
    gaussianBlur(blue);
    gaussianBlur(green);
    gaussianBlur(red);
}

double** Smoothing::createKernel(double **input, int size){
    double sigma = 1;
    int W = size;
    double mean = W / 2;
    double sum = 0.0; // For accumulating the kernel values
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


void Smoothing::convertToGrayScale(){
}

void Smoothing::doSmoothing(std::vector<unsigned char>& colorVec){
    
    std::vector<double> pushColorVect;

    for(int i{0}; i < colorVec.size(); i++){
        pushColorVect.push_back(colorVec[i]); 
    }
    

    for (int v{1}; v < (hgt-2)*3; v++){
        for (int u{1}; u < (wdt-2)*3; u++){
            double sum = 0; 
            for(int j{-1}; j <= 1; j++){
                for(int i{-1}; i<= 1; i++){ 
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

    std::vector<double> pushColorVect;
    size_t pad_rows = (hgt)/2; 
    size_t pad_cols = (wdt)/2; 

    for(int i{0}; i < colorVec.size(); i++){
        pushColorVect.push_back(colorVec[i]); 
    }
    
    double sumGau{};
    //double gusM[3][3]{ {-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1} }; 
    double **gusM;
    gusM = createKernel(gusM, 3);


    for(int i{}; i<3; ++i){
        for(int j{}; j<3; ++j){
            std::cout << gusM[i][j] << " ";
            sumGau+=gusM[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    unsigned char** paddedImg{nullptr}; 
    paddedImg = new unsigned char*[(hgt+(2*pad_rows))*3]{}; 

    for(size_t i{0}; i < (hgt+(2*pad_rows))*3; i++){
        paddedImg[i] = new unsigned char[(wdt+(2*pad_cols))*3]{}; 
    }
    
    

    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
            paddedImg[i][j] = colorVec[k];
            //if(i>=pad_rows && j>=pad_cols){
                k++;  
            //}                      
        }
    }

    // for(size_t i{0}, k{0}; i < pad_rows; i++ ){
    //     for(size_t j{0}; j< pad_cols; j++){
    //         paddedImg[i][j] = colorVec[k]; 
    //         k++; 
    //     }
    // }

    // for(size_t i{(pad_rows + hgt)*3}, k{colorVec.size()}; i > (pad_rows + hgt)*3-pad_rows; i-- ){
    //     for(size_t j{(pad_cols + wdt)*3}; j > (pad_cols + wdt)*3-pad_cols; j--){
    //         paddedImg[i][j] = colorVec[k]; 
    //         k--; 
    //     }
    // }

    for(size_t i{0}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{0}; j< (pad_cols + wdt)*3; j++){
            std::cout<<  static_cast<short>(paddedImg[i][j]) << "    ";               
        }
        std::cout<< std::endl; 
    }

    



    



    unsigned char** paddedImgCopy{nullptr}; 
    paddedImgCopy = new unsigned char*[(hgt+(2*pad_rows))*3]{}; 

    for(size_t i{0}; i < (hgt+(2*pad_rows))*3; i++){
        paddedImgCopy[i] = new unsigned char[(wdt+(2*pad_cols))*3]{}; 
    }

    for(size_t i{0}; i < (hgt+(2*pad_rows))*3; i++ ){
        for(size_t j{0}; j< (wdt+(2*pad_cols))*3; j++){
            paddedImgCopy[i][j] = paddedImg[i][j];      
        }
    }
   
    // int counter{0}; 
    // std::cout << "Before\n";
    // for(size_t v{pad_rows}; v < pad_rows+3; v++ ){
    //     for(size_t u{pad_cols}; u< pad_cols+3; u++){
    //         std::cout << (short)paddedImgCopy[v][u] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;

    for(size_t v{pad_rows}; v < (pad_rows + hgt)*3; v++ ){
        for(size_t u{pad_cols}; u< (pad_cols + wdt)*3; u++){
            std::vector<double> matrix;
            matrix.push_back(static_cast<double>(paddedImgCopy[v-1][u-1]) * gusM[0][0]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v-1][u]) *   gusM[0][1]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v-1][u+1]) * gusM[0][2]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v][u-1] )*   gusM[1][0]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v][u] )*     gusM[1][1]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v][u+1] )*   gusM[1][2]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v+1][u-1] )* gusM[2][0]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v+1][u] )*   gusM[2][1]); 
            matrix.push_back(static_cast<double>(paddedImgCopy[v+1][u+1] )* gusM[2][2]);  
            double sum{0};    
            for(auto x: matrix){
                sum+=x;
            }
            //std::cout << "sum/9" << sum/9 << std::endl;
            paddedImgCopy[v][u] = std::round(sum); 

        }

    }

    //std::cout << "After\n";
    // for(size_t v{pad_rows}; v < pad_rows+3; v++ ){
    //     for(size_t u{pad_cols}; u< pad_cols+3; u++){
    //         std::cout << (short)paddedImgCopy[v][u] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;


    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
            colorVec[k] = paddedImgCopy[i][j]; 
            k++; 
        }     
    }

    std::cout << std::endl;
    for(int i{}; i<3; ++i){
        delete[] gusM[i];
    }
    delete[] gusM;

}; 



std::vector<unsigned char> Smoothing::getBlue() const { return blue; }
std::vector<unsigned char> Smoothing::getGreen() const { return green; }
std::vector<unsigned char> Smoothing::getRed() const { return red; }