#include "files/loader.h"
#include "files/writer.h"
#include <iostream>
#include "files/exception.h"
#include "bmp/bmp.h"
#include "filters/filter.h"
#include "filters/histogram.h"
#include "filters/smoothing.h"
#include "filters/grayScale.h"
#include "filters/sobel.h"
#include "filters/canny.h"


int main(){
    std::string file;
    std::cin >> file;
    std::string name{"../assets/"}; 
    name.append(file);
    name.append(".bmp");
    std::cout << name << std::endl;

    BMP bmp{name};  

    std::cout << "GrayScale begin" << std::endl; 

    //Histogram hist{ bmp.getBlue(), bmp.getGreen(), bmp.getRed()}; 
    GrayScale gray{ bmp.getBlue(), bmp.getGreen(), bmp.getRed(), bmp.getWidth(),  bmp.getHeight() }; 

    std::cout << "GrayScale end" << std::endl; 
 
    //Smoothing smooth{ gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight() }; 
    // Sobel sobel{gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight()}; 
    // auto grad{sobel.createGradMatrix()}; 

    // for(const auto& i: grad){
    //     for(const auto& j: i){
    //         std::cout << "j= " << j << "\n"; 
    //     }
    // }


    Canny canny{gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight()};

    //bmp.setColors(sobel.getBlue(), sobel.getGreen(), sobel.getRed()); 
}
