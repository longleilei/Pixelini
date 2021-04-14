#include <iostream>


#include "filters/histogram.h" 


Histogram::Histogram(const std::vector<char>& _blue, const std::vector<char>& _green, const std::vector<char>& _red){

    std::cout << "before copy" << std::endl; 

    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));

    fillHistogram(); 
}

void Histogram::fillHistogram(){

    for(int i{0}; i < blue.size(); i++){
        blueHist[blue[i]]++; 
    }

    std::cout << blueHist['g'] << std::endl; 
}



