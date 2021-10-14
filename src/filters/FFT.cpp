#include "filters/FFT.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "complex.h"
#include <complex>


FFT::FFT(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
    const std::vector<unsigned char> &_red, unsigned int width, unsigned int height): Filter{_blue, _green, _red, width, height}{

    M = wdt; 
    L = hgt; 

    // for(int m{0}; m < blue.size(); m++){
    //     std::cout << (short) blue[m] << " ";       
    // }

    // std::cout << std::endl;


    //std::vector<unsigned char> test{1,0,1,0}; 
    auto result = fft(blue);
    // for(int m{0}; m < result.size(); m++){
    //     std::cout << result[m] << " ";       
    // }

    // std::cout << std::endl;

    blue = ifft(result); 
    result = fft(green);
    green = ifft(result); 
    result = fft(red); 
    red = ifft(result);

    std::reverse(blue.begin(), blue.end()); 
    std::reverse(green.begin(), green.end()); 
    std::reverse(red.begin(), red.end()); 


     
    // for(int m{0}; m < result2.size(); m++){
    //     std::cout << result2[m] << " ";       
    // }
    
};

std::vector<Complex> FFT::fft(std::vector<unsigned  char>& img){

    std::vector<Complex> complexVec;  
    for(int i{}; i < img.size(); i++){
        complexVec.emplace_back(img[i], 0); 
    } 

    fftRec(complexVec, complexVec.size()); 

    return complexVec; 

}

void FFT::fftRec(std::vector<Complex>& complexVec, int n){

    if(n <= 1){
        return; 
    }


    std::vector<Complex> even; 
    std::vector<Complex> odd; 

    for(int i{}; i < n/2; i++ ){
        even.push_back(complexVec[i*2]); 
        odd.push_back(complexVec[i*2+1]); 
    }

    

    fftRec(even, n/2); 
    fftRec(odd, n/2); 

    //std::cout << n << std::endl; 

    for(int i{}; i < n/2; i++){
        Complex t{cos((2 * M_PI*i) / n ), -sin((2 * M_PI*i) / n)}; 
        //Complex t{0, 0}; 

        t = t * odd[i]; 
        complexVec[i] = even[i] + t; 
        complexVec[n/2 + i] = even[i] - t; 
    }

    // std::cout << std::endl; 
}

std::vector<unsigned char> FFT::ifft(std::vector<Complex>& complexVec){

    std::vector<unsigned char> img;
    ifftRec(complexVec, complexVec.size()); 

    for(int i{}; i < complexVec.size(); i++){
        img.push_back(complexVec[i].getReal()); 
        //std::cout << complexVec[i] << " ";  
    } 
    //std::cout <<  << std::endl

    return img; 
}

void FFT::ifftRec(std::vector<Complex>& complexVec, int n){
    if(n <= 1){
        return; 
    }


    std::vector<Complex> even; 
    std::vector<Complex> odd; 

    for(int i{}; i < n/2; i++ ){
        even.push_back(complexVec[i*2]); 
        odd.push_back(complexVec[i*2+1]); 
    }

    

    fftRec(even, n/2); 
    fftRec(odd, n/2); 

    //std::cout << n << std::endl; 

    for(int i{}; i < n/2; i++){
        //std::cout << "i " << i << " ";  
        Complex t{cos((2 * M_PI*i) / n ), -sin((2 * M_PI*i) / n)}; 
        t = t * odd[i]; 
        // complexVec[i] = Complex::conjugate(even[i] + t); 
        complexVec[i] = even[i] + t; 
        complexVec[i] = complexVec[i]/n; 
        complexVec[n/2 + i] = even[i] - t; 
        // complexVec[n/2 + i] = Complex::conjugate(even[i] - t); 
        complexVec[n/2 + i] = complexVec[n/2 + i]/n; 

    }

    // std::cout << std::endl; 
}


