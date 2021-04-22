#include <iostream>
#include <algorithm> 

#include "filters/histogram.h" 


Histogram::Histogram(const std::vector<char>& _blue, const std::vector<char>& _green, const std::vector<char>& _red){

    

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

    // for(int i{0}; i < 50; i++){
    //     std::cout << static_cast<short>(blue[i]) << " ";
        
    // }

    std::cout << std::endl;  


    int numOfPixels{}; 
    std::unique_ptr<int[]> pdfIntensity(new int[255]); 

    for(auto it = blueHist.begin(); it != blueHist.end(); it++){
        numOfPixels += it->second; 
        //std::cout << static_cast<short>(it->first) << " " << it->second << " " << "\n";
    }

  
    //each intensity value divide by the numOfPixels
    for(auto it = blueHist.begin(), int i{0}; it != blueHist.end(); it++, i++){
        pdfIntensity[i] = it->second / numOfPixels; 
    }


    // std::cout << "Num Of Pixels" << numOfPixels <<std::endl; //2359296 











    // auto minBlue = std::min_element(blueHist.begin(),blueHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second < second.second; }); 
    // auto maxBlue = std::min_element(blueHist.begin(),blueHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second > second.second; }); 

    // auto minRed = std::min_element(redHist.begin(),redHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second < second.second; }); 
    // auto maxRed = std::min_element(redHist.begin(),redHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second > second.second; }); 

    // auto minGreen = std::min_element(greenHist.begin(),greenHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second < second.second; }); 
    // auto maxGreen = std::min_element(greenHist.begin(),greenHist.end(), [](std::pair<char, int> first,std::pair<char, int> second ){return first.second > second.second; }); 

    // auto scaleBlue = 255.0/((maxBlue->first - minBlue->first ));
    // auto scaleRed = 255.0/((maxRed->first - minRed->first ));
    // auto scaleGreen = 255.0/((maxGreen->first - minGreen->first ));


    // for (int i{0}; i < blue.size(); i++){
    //     blue[i] = scaleBlue * (blue[i] - minBlue->first); 
    // }

    // for (int i{0}; i < red.size(); i++){
    //     red[i] = scaleRed * (red[i] - minRed->first); 
    // }

    // for (int i{0}; i < green.size(); i++){
    //     green[i] = scaleGreen * (green[i] - minGreen->first); 
    // }




}

std::vector<char> Histogram::getBlue() const{return blue; }
std::vector<char> Histogram::getGreen() const{ return green; }
std::vector<char> Histogram::getRed() const{ return red; }



