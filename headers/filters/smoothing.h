#pragma once
#include <vector>




class Smoothing{

    std::vector<char> blue;
    std::vector<char> green;
    std::vector<char> red;
    unsigned int wdt; 
    unsigned int hgt; 

    double mask[3][3] = {
        {0.75, 1.25, 0.75}, 
        {1.25, 0.200, 1.25}, 
        {0.75, 1.25, 0.75}
    }; 

    public: 
    Smoothing(const std::vector<char> &_blue, const std::vector<char> &_green, const std::vector<char> &_red, unsigned int width, unsigned int height );
   
    void doSmoothing(std::vector<char>& colorVec); 

    std::vector<char> getBlue() const;
    std::vector<char> getGreen() const;
    std::vector<char> getRed() const;
}; 