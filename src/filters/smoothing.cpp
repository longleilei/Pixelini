#include <iostream>
#include "filters/smoothing.h" 
#include <cmath>
#include <numeric>

Smoothing::Smoothing(const std::vector<char> &_blue, const std::vector<char> &_green, const std::vector<char> &_red, unsigned int width, unsigned int height ): wdt{width}, hgt{height}{


    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));
    

    // for(int i{0}; i<=200; i++){
    //     std::cout << static_cast<short>(blue[i]) << " ";           
    // }

    //  std::cout <<  std::endl; 

    // for(int i{0}; i<=200; i++){
    //     std::cout << static_cast<short>(green[i]) << " ";           
    // }

    //std::cout << "SIZE BLUE:" <<blue.size()/3 <<std::endl; 
    

    // doSmoothing(blue); 
    // doSmoothing(green); 
    // doSmoothing(red); 

    gaussianBlur(blue); 
    gaussianBlur(green); 
    gaussianBlur(red); 
}

void Smoothing::doSmoothing(std::vector<char>& colorVec){
    
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


    // for (int v{0}; v < hgt; v++){
    //     for (int u{0}; u < wdt*3; u++){
    //         double sum = 0; 
    //         for(int j{-1}; j <= 1; j++){
    //             for(int i{-1}; i<= 1; i++){
    //                 //int p = colorVec[u*wdt + v]; 
    //                 int p = *colorPixelIter; 
    //                 double c = mask[j+1][i+1]; 
    //                 sum += c * p; 
    //             }
    //         }
    //         //colorVec[u*wdt + v] = round(sum);
    //         std::cout << "before: " << (short) *colorPixelIter << std::endl; 
    //         *colorPixelIter = round(sum); 
    //         std::cout << "after: " << (short) *colorPixelIter << " " << std::endl; 
    //         pushColorVect.push_back(*colorPixelIter); 
    //         colorPixelIter++; 
    //     }
    // }

    // colorVec.clear(); 
    // std::copy(pushColorVect.begin(), pushColorVect.end(), std::back_inserter(colorVec));



}

void Smoothing::gaussianBlur(std::vector<char>& colorVec){

    std::vector<double> pushColorVect;

    size_t pad_rows = (hgt-1)/2; 
    size_t pad_cols = (wdt-1)/2; 

    for(int i{0}; i < colorVec.size(); i++){
        pushColorVect.push_back(colorVec[i]); 
    }

    //create kernel - kernel size = hgt x wdt 
    double** kernel{nullptr}; 
    kernel = new double*[11]{}; 

    for(size_t i{0}; i < 11; i++){
        kernel[i] = new double[11]{}; 
    }

    //K & sigma has to change; we take K=1 and sigma=1
    //formula is K * exp((s^2 + t^2)/2*sigma^2)

    //std::cout << hgt*3 << " " << wdt*3 << std::endl; 
    //kernel size is 711 * 705 
    double sigma{1}; 

    for(size_t i{1}; i < 11; i++ ){
        for(size_t j{1}; j< 11; j++){
            kernel[i][j] = std::exp(-(i*i + j*j) /( 2.0 * sigma * sigma) );            
        }
    }

    // for(size_t i{0}; i < 10; i++ ){
    //     for(size_t j{0}; j< 10; j++){
    //         std::cout << kernel[i][j] << " ";         
    //     }
    // }



    




    
    //std::vector<std::vector<char>> paddedImg((hgt+(2*pad_rows)) * (wdt+(2*pad_cols))); 
    char** paddedImg{nullptr}; 
    paddedImg = new char*[(hgt+(2*pad_rows))*3]{}; 

    for(size_t i{0}; i < (hgt+(2*pad_rows))*3; i++){
        paddedImg[i] = new char[(wdt+(2*pad_cols))*3]{}; 
    }


    std::cout << (pad_rows + hgt) << std::endl; 
    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
            paddedImg[i][j] = colorVec[k]; 
            k++; 
            
        }
    }

    //intensify the color
    // for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
    //     for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
    //         paddedImg[i][j] += 50; 
    //         k++; 
    //     }
    // }

    //copy array 
    char** paddedImgCopy{nullptr}; 
    paddedImgCopy = new char*[(hgt+(2*pad_rows))*3]{}; 

    for(size_t i{0}; i < (hgt+(2*pad_rows))*3; i++){
        paddedImgCopy[i] = new char[(wdt+(2*pad_cols))*3]{}; 
    }

    for(size_t i{0}; i < (hgt+(2*pad_rows))*3; i++ ){
        for(size_t j{0}; j< (wdt+(2*pad_cols))*3; j++){
            paddedImgCopy[i][j] = paddedImg[i][j];      
        }
    }

   

    for(size_t v{pad_rows}; v < (pad_rows + hgt)*3; v++ ){
        for(size_t u{pad_cols}; u< (pad_cols + wdt)*3; u++){
            std::vector<double> matrix; 
            matrix.push_back(paddedImg[v-1][u-1] * gaussianKernel[0][0]); 
            matrix.push_back(paddedImg[v-1][u] *   gaussianKernel[0][1]); 
            matrix.push_back(paddedImg[v-1][u+1] * gaussianKernel[0][2]); 
            matrix.push_back(paddedImg[v][u-1] *   gaussianKernel[1][0]); 
            matrix.push_back(paddedImg[v][u] *     gaussianKernel[1][1]); 
            matrix.push_back(paddedImg[v][u+1] *   gaussianKernel[1][2]); 
            matrix.push_back(paddedImg[v+1][u-1] * gaussianKernel[2][0]); 
            matrix.push_back(paddedImg[v+1][u] *   gaussianKernel[2][1]); 
            matrix.push_back(paddedImg[v+1][u+1] * gaussianKernel[2][2]);
            double sum = std::accumulate(matrix.begin(), matrix.end(), 0); 
            paddedImgCopy[v][u] = sum; 
        }
    }


    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
            colorVec[k] = paddedImgCopy[i][j]; 
            k++; 
        }
    }

    //std::cout << pad_rows << " " << pad_cols << std::endl; 








    

    // for (int v{1}; v < (hgt-2)*3; v++){
    //     for (int u{1}; u < (wdt-2)*3; u++){
    //         double sum = 0; 
    //         for(int j{-1}; j <= 1; j++){
    //             for(int i{-1}; i<= 1; i++){
    //                 int p = pushColorVect[((v+j)*wdt+(u+i))];
    //                 double c = gaussianKernel[j+1][i+1]; 
    //                 sum += c * p; 
    //             }
    //         }
    //         colorVec[(v*wdt + u)] = round(sum); //or 
    //     }
    // }    

}; 



std::vector<char> Smoothing::getBlue() const { return blue; }
std::vector<char> Smoothing::getGreen() const { return green; }
std::vector<char> Smoothing::getRed() const { return red; }