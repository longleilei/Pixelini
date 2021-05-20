#include "files/loader.h"
#include "files/writer.h"
#include <iostream>
#include "files/exception.h"
#include "bmp/bmp.h"
#include "filters/histogram.h"
#include "filters/smoothing.h"


int main(){
    std::string file;
    std::cin >> file;
    std::string name{"../assets/"}; 
    name.append(file);
    name.append(".bmp");
    std::cout << name << std::endl;

    BMP bmp{name};  

    //Histogram hist{ bmp.getBlue(), bmp.getGreen(), bmp.getRed()}; 
    Smoothing smooth{ bmp.getBlue(), bmp.getGreen(), bmp.getRed(),  bmp.getWidth(),  bmp.getHeight() }; 

    bmp.setColors(smooth.getBlue(), smooth.getGreen(), smooth.getRed()); 
}
