#pragma once
#include <vector>




class Smoothing{

    std::vector<char> blue;
    std::vector<char> green;
    std::vector<char> red;
    unsigned int wdt; 
    unsigned int hgt; 

    double mask[3][3] = {
        {0.075, 0.125, 0.075}, 
        {0.125, 0.20, 0.125}, 
        {0.075, 0.125, 0.075}
    }; 

    double gaussianKernel[3][3] = {
        {0.3679, 0.6065, 0.3679}, 
        {0.6065, 1, 0.6065}, 
        {0.3679, 0.6065, 0.3679}
    }; 

    public: 
    Smoothing(const std::vector<char> &_blue, const std::vector<char> &_green, const std::vector<char> &_red, unsigned int width, unsigned int height );
   
    void doSmoothing(std::vector<char>& colorVec); 

    void gaussianBlur(std::vector<char>& colorVec); 

    std::vector<char> getBlue() const;
    std::vector<char> getGreen() const;
    std::vector<char> getRed() const;
}; 