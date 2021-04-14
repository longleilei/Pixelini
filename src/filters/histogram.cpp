#include <iostream>
#include <algorithm> 

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

    for(int i{0}; i < green.size(); i++){
        greenHist[green[i]]++; 
    }

    for(int i{0}; i < red.size(); i++){
        redHist[red[i]]++; 
    }


    for(auto it = blueHist.begin(); it != blueHist.end(); ++it){
        //std::cout << static_cast<short>(it->first) << " " << "\n";
        //std::cout << static_cast<short>(it->first) << " " << it->second << " " << "\n";
    }

    auto minBlue = std::min_element(blueHist.begin(),blueHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second < second.second; }); 
    auto maxBlue = std::min_element(blueHist.begin(),blueHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second > second.second; }); 

    float histRatio = 255.0f / (maxBlue->second - minBlue->second ); 
    std::cout << maxBlue->second << " "<< minBlue->second << " "; 

    for(auto pixel: blue ){
        pixel -= minBlue->second; 
        pixel*=histRatio; 
        std::cout << static_cast<short>(pixel) << " "; 
    } 

   


    


        
        
    //std::cout << static_cast<short>(minBlue->first) << " " << minBlue->second <<std::endl; 
    
    





}



