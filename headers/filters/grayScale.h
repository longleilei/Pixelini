#pragma once 
#include <vector>
#include "filters/filter.h"

class GrayScale : public Filter{


public:

    GrayScale(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height);
    void convertToGrayScale();

}; 