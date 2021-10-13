// #include "files/loader.h"
// #include "files/writer.h"
// #include <iostream>
// #include "files/exception.h"
// #include "bmp/bmp.h"
// #include "filters/filter.h"
// #include "filters/histogram.h"
// #include "filters/smoothing.h"
// #include "filters/grayScale.h"
// #include "filters/sobel.h"
// #include "filters/canny.h"
// #include "filters/fourier.h"
// #include "filters/fourierFilters.h"
// #include "filters/FFT.h" 
// #include "utility/resize.h"
// #include "utility/complex.h"

#include <cmath>


int main(){

    auto t{cos((2 * M_PI*4) / 1 )};  
    auto tv {-sin((2 * M_PI*5) / 10)}; 


    std::string file;
    std::cin >> file;
    std::string name{"../assets/"}; 
    name.append(file);
    name.append(".bmp");
    std::cout << name << std::endl;

    BMP bmp{name};  

    //Histogram hist{ bmp.getBlue(), bmp.getGreen(), bmp.getRed()}; 
    //GrayScale gray{ bmp.getBlue(), bmp.getGreen(), bmp.getRed(), bmp.getWidth(),  bmp.getHeight() }; 

 
    //Smoothing smooth{ gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight() }; 
    //Sobel sobel{gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight()}; 
    // auto grad{sobel.createGradMatrix()}; 

    // for(const auto& i: grad){
    //     for(const auto& j: i){
    //         std::cout << "j= " << j << "\n"; 
    //     }
    // }


    //Canny canny{bmp.getBlue(), bmp.getGreen(), bmp.getRed(),  bmp.getWidth(),  bmp.getHeight()};

    //Resize resize{bmp.getBlue(), bmp.getGreen(), bmp.getRed(),  bmp.getWidth(),  bmp.getHeight()}; 

    //bmp.saveImg(bmp.getWidth(),  bmp.getHeight(), smooth.getBlue(), smooth.getGreen(), smooth.getRed()); 

    //bmp.saveImg(bmp.getWidth(),  bmp.getHeight(), smooth.getBlue(), smooth.getGreen(), smooth.getRed()); 

    //Complex complex{-1, 3};
    //Complex complex2{1,2};
    //std::cout << complex/complex2 << std::endl; 

    //pass it to Fourier? 
    //Complex complexArr[bmp.getHeight() * bmp.getWidth()]; 


    FFT fft{gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight()}; 




    //Fourier fourier{gray.getBlue(), gray.getGreen(), gray.getRed(),  bmp.getWidth(),  bmp.getHeight()}; 
    //auto dft{fourier.createSignal(gray.getBlue())};

    // std::cout << std::endl; 
    // std::cout << std::endl; 
    // std::cout << std::endl; 

    //FourierFilters filteredMatrix{dft, bmp.getWidth(),  bmp.getHeight()}; 

    // std::cout << "hello from main "<<  std::endl; 
    // fourier.printMatrixComplex(dft, 4);

    //auto filtered{filteredMatrix.filterMatrix()}; 


    //fourier.returnPixels(filtered); 


    //bmp.saveImg(bmp.getWidth(),  bmp.getHeight(), fourier.returnPixels(filtered), fourier.returnPixels(filtered), fourier.returnPixels(filtered)); 

    


}
