#pragma once 
#include <vector>

class Filter {
    
protected: 
    std::vector<unsigned char> blue;
    std::vector<unsigned char> green;
    std::vector<unsigned char> red;
    unsigned int wdt;
    unsigned int hgt;

public: 

    Filter(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green,  
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height);

    std::vector<unsigned char> getBlue() const;
    std::vector<unsigned char> getGreen() const;
    std::vector<unsigned char> getRed() const;


}; 

