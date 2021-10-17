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


    complBlue = fft(blue); 

    // blue = ifft(result); 
 
    complGreen = fft(green); 
    
    // green = ifft(result);
    complRed = fft(red); 
    
    // red = ifft(result);

    // std::reverse(blue.begin(), blue.end()); 
    // std::reverse(green.begin(), green.end()); 
    // std::reverse(red.begin(), red.end()); 


     
    // for(int m{0}; m < result2.size(); m++){
    //     std::cout << result2[m] << " ";       
    // }
    
};

std::vector<Complex>FFT::getcomplBlue(){
    return complBlue; 
}
std::vector<Complex>FFT::getcomplGreen(){
    return complGreen; 
}
std::vector<Complex>FFT::getcomplRed(){
    return complRed; 
}

void FFT::reverseVectors(){

    std::reverse(blue.begin(), blue.end()); 
    std::reverse(green.begin(), green.end()); 
    std::reverse(red.begin(), red.end()); 
};


std::vector<std::vector<Complex>> FFT::createMatrixFromVector(std::vector<Complex> colorVec){

    std::vector<Complex> tmp1(M, {0,0});
    std::vector<std::vector<Complex>> matrix(L, tmp1);

    for(int i{0}, k{0}; i < L; i++ ){
        for(int j{0}; j< M; j++){
            matrix[i][j] = colorVec[k];
            // std::cout << colorVec[k] << "     "; 
            k++;             
        }
        k++;
        //std::cout << std::endl; 
    }

   

    return matrix; 

}

std::vector<Complex> FFT::createVectorFromMatrix(std::vector<std::vector<Complex>> colorMat){

    std::vector<Complex> colorVec;

    for(int i{0}; i < L; i++ ){
        for(int j{0}; j< M; j++){
            colorVec.push_back(colorMat[i][j]); 
        }
    }

    for(int i{0}; i < colorVec.size(); i++ ){
        std::cout << colorVec[i] << "     ";   
    }


    std::cout << std::endl;
    std::cout << std::endl;

    return colorVec; 

}

void FFT::setVectors(std::vector<unsigned char> _blue, std::vector<unsigned char> _green, std::vector<unsigned char> _red){

    blue.clear(); 
    green.clear(); 
    red.clear(); 

    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));
}


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


