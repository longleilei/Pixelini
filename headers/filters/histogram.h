#pragma once 
#include <vector>
#include<map>


class Histogram{

    std::vector<char>blue; 
    std::vector<char>green; 
    std::vector<char>red; 
    std::map<char, int>redHist; 
    std::map<char, int>greenHist; 
    std::map<char, int>blueHist; 

    void fillHistogram(); 


public: 
    Histogram(const std::vector<char>& _blue, const std::vector<char>& _green, const std::vector<char>& _red); 


}; 
