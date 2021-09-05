#pragma once 
#include <vector>
#include "../filters/filter.h"

class Resize : public Filter {



std::vector<std::vector<unsigned char>> insertSubMatrix(std::vector<unsigned char>& colorVec, int scale); 

public: 

Resize(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height); 

void convert2D(std::vector<unsigned char>& colorVec, std::vector<std::vector<unsigned char>>& minipic); 

//void addColumn(); 


void increaseSize(int scale); 

}; 