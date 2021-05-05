#include <iostream>
#include "filters/smoothing.h" 
#include <cmath> 

Smoothing::Smoothing(const std::vector<char> &_blue, const std::vector<char> &_green, const std::vector<char> &_red, unsigned int width, unsigned int height ): wdt{width}, hgt{height}{


    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));
    

    doSmoothing(blue); 
    doSmoothing(green); 
    doSmoothing(red); 
}

void Smoothing::doSmoothing(std::vector<char>& colorVec){
    
    std::vector<double> pushColorVect;
    auto colorPixelIter{colorVec.begin()}; 


    for (int v{0}; v < hgt; v++){
        for (int u{0}; u < wdt*3; u++){
            double sum = 0; 
            for(int j{-1}; j <= 1; j++){
                for(int i{-1}; i<= 1; i++){
                    //int p = colorVec[u*wdt + v]; 
                    int p = *colorPixelIter; 
                    double c = mask[j+1][i+1]; 
                    sum += c * p; 
                }
            }
            //colorVec[u*wdt + v] = round(sum);
            std::cout << "before: " << (short) *colorPixelIter << std::endl; 
            *colorPixelIter = round(sum); 
            std::cout << "after: " << (short) *colorPixelIter << " " << std::endl; 
            pushColorVect.push_back(*colorPixelIter); 
            colorPixelIter++; 
        }
    }

    colorVec.clear(); 
    std::copy(pushColorVect.begin(), pushColorVect.end(), std::back_inserter(colorVec));



}

std::vector<char> Smoothing::getBlue() const { return blue; }
std::vector<char> Smoothing::getGreen() const { return green; }
std::vector<char> Smoothing::getRed() const { return red; }