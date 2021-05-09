#include <iostream>
#include "filters/smoothing.h" 
#include <cmath> 

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

    for(int i{0}; i < colorVec.size(); i++){
        pushColorVect.push_back(colorVec[i]); 
    }



    size_t pad_rows = (hgt-1)/2; 
    size_t pad_cols = (wdt-1)/2; 
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

    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
            paddedImg[i][j] += 50; 
            k++; 
        }
    }

    for(size_t i{pad_rows}, k{0}; i < (pad_rows + hgt)*3; i++ ){
        for(size_t j{pad_cols}; j< (pad_cols + wdt)*3; j++){
            colorVec[k] = paddedImg[i][j]; 
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