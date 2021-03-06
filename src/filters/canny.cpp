#include <iostream>
#include "filters/canny.h" 
#include "filters/smoothing.h" 
#include "filters/sobel.h" 
#include <cmath>
#include <numeric>
#include <iomanip>

Canny::Canny(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
const std::vector<unsigned char> &_red, unsigned int width, unsigned int height ): Filter{_blue, _green, _red, width, height}{

    applyNoiseReduction(); 
    applySobel(); 
    nonMaxSuppression(sobelGradVect); 
    
}

void Canny::applyNoiseReduction(){

    Smoothing smooth{ blue, green, red,  wdt,  hgt }; 
    blue = smooth.getBlue();
    green = smooth.getGreen(); 
    red = smooth.getRed(); 
}

void Canny::applySobel(){
    Sobel sobel{ blue, green, red,  wdt,  hgt };

    
    blue =  sobel.getBlue();
    green = sobel.getGreen();
    red = sobel.getRed(); 

    sobelGradVect = sobel.createGradMatrix(); 
    
}

void Canny::nonMaxSuppression(std::vector<std::vector<unsigned int>> img){

    auto copyAfterVertical = img; 

    for(int j{1}; j < hgt-1; j++ ){
        for (int i{1}; i < wdt-1; i++){
            if(img[j][i] != 0){
                if(img[j][i] < img[j][i-1] || img[j][i] < img[j][i+1]){
                        copyAfterVertical[j][i] = 0;
                    }
            
                if((img[j][i] < img[j-1][i+1]) || (img[j][j] < img[j+1][i-1])){
                        copyAfterVertical[j][i] = 0;
                    }
                
                if((img[j][i] < img[j-1][i]) || (img[j][j] < img[j+1][i])){
                        copyAfterVertical[j][i] = 0;
                    }

                if((img[j][i] < img[j+1][i+1]) || (img[j][j] < img[j-1][i-1])){
                        copyAfterVertical[j][i] = 0;
                    }
                }
            }
        }

    // for (int v{20}; v < 40; v++){
    //     for (int u{20}; u < 40; u++){
    //         std::cout << std::setw(5) << copyAfterVertical[u][v] << " "; 
    //     }
    //     std::cout << std::endl;
    // }  

    hysteresisThresholding(copyAfterVertical); 
}


void Canny::hysteresisThresholding(std::vector<std::vector<unsigned int>> img){
    int maxThresh = 64; 
    int minThresh = 16; 

    for(int j{1}; j < hgt; j++ ){
        for (int i{1}; i < wdt; i++){
            if(img[j][i] > maxThresh){
                img[j][i] = 255; 
            } else if((img[j][i] < maxThresh) && (img[j][i] > minThresh)){
                img[j][i] = 128; 
            } else {
                img[j][i] = 0; 
            }
        }
    }

    //if pixel is 128 but neighbors are 255, we set 128 to 255
    //if no neighbors, we set it to 0 
    bool flag{true}; 
    while(flag){
        flag = false; 
        for(int j{1}; j < hgt-1; j++ ){
            for (int i{1}; i < wdt-1; i++){
                if(img[j][i] > 0){
                    if(img[j][i] == 128){
                        if((img[j-1][i] == 255) || (img[j-1][i-1] == 255)
                        || (img[j][i-1] == 255) || (img[j+1][i-1] == 255) 
                        || (img[j+1][i] == 255) || (img[j+1][i+1] == 255) 
                        || (img[j][i+1] == 255) || (img[j-1][i+1] == 255)){
                            img[j][i] = 255; 
                            flag = true; 
                        }
                    }
                }

            }
        }
    }

    // for (int v{0}; v < 7; v++){
    //     for (int u{0}; u < 6; u++){
    //         std::cout << std::setw(5) << img[u][v] << " "; 
    //     }
    //     std::cout << std::endl;
    // }  
}



