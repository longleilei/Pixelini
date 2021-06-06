#pragma once 
#include <vector>
#include "filters/filter.h"


class Sobel : public Filter {

    int horizontalSobel[3][3] = {
        {-1, -2, -1}, 
        { 0, 0, 0 }, 
        {1, 2, 1 }
    };

    int verticalSobel[3][3] = {
        {-1, 0, 1}, 
        {-2, 0, 2}, 
        {-1, 0, 1}
    };

public: 

    Sobel(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height);

    void enchanceEdges(std::vector<unsigned unsigned char> &colorVec); 


}; 