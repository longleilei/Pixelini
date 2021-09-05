#include <iostream>
#include "filters/grayScale.h" 

GrayScale::GrayScale(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green,  
const std::vector<unsigned char> &_red, unsigned int width, unsigned int height): Filter{_blue, _green, _red, width, height}{

    convertToGrayScale(); 
}



void GrayScale::convertToGrayScale(){


    std::vector<char> pixels;


    for(int i{0}; i < (wdt * hgt); i++){
       int gray = 0.2126*red[i] + 0.7152*green[i] + 0.0722*blue[i]; 
       blue[i] = gray; 
       green[i] = gray; 
       red[i] = gray; 
    }

    for(int i{0}; i < (wdt * hgt); i++){
       pixels.push_back(blue[i]); 
    }

    for(int i{0}; i < (wdt * hgt); i++){
       pixels.push_back(green[i]); 
    }

    for(int i{0}; i < (wdt * hgt); i++){
       pixels.push_back(red[i]); 
    }

    std::cout << std::endl; 


    for(size_t i{0}; i < blue.size(); i++){
        blue[i] = pixels[i]; 
    }

    for(size_t i{blue.size()}, k{0}; i < blue.size()*2; i++){
        green[k] = pixels[i]; 
        k++; 
    }

    for(size_t i{ blue.size()*2}, k{0}; i < blue.size()*3; i++){
        red[k] = pixels[i]; 
        k++; 
    }



}



