#pragma once 
#include <vector>

class GrayScale{

    std::vector<unsigned char> blue;
    std::vector<unsigned char> green;
    std::vector<unsigned char> red;

public:

    GrayScale(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green);

    void convertToGrayScale();

    std::vector<unsigned char> getBlue() const;
    std::vector<unsigned char> getGreen() const;
    std::vector<unsigned char> getRed() const;

}; 