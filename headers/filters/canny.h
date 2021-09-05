#pragma once 
#include <vector>
#include "filters/filter.h"

class Canny : public Filter {

    //multiply with 1/159
    double noiseRedFilter[5][5] = {
        {0, 2, 3, 2, 0}, 
        {2, 7, 11, 7, 2}, 
        {3, 11, 18, 11, 3}, 
        {2, 7, 11, 7, 2}, 
        {0, 2, 3, 2, 0}
    }; 

    std::vector<std::vector<unsigned int>> sobelGradVect; 

public: 

    Canny(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height);

    void applyNoiseReduction(); 
    void applySobel(); 
    void nonMaxSuppression(std::vector<std::vector<unsigned int>> img); 
    void hysteresisThresholding(std::vector<std::vector<unsigned int>> img); 



}; 