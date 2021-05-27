#include <iostream>
#include "filters/grayScale.h" 

void GrayScale::GrayScale(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green){

    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));

    convertToGrayScale(); 
}


void GrayScale::convertToGrayScale(){

}