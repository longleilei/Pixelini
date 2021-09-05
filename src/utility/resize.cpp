#include <iostream>
#include "utility/resize.h" 
#include <iomanip>
#include <math.h>

Resize::Resize(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
const std::vector<unsigned char> &_red, unsigned int width, unsigned int height ): Filter{_blue, _green, _red, width, height}{

    int scale{2}; 
    increaseSize(scale);  
}

void Resize::convert2D(std::vector<unsigned char>& colorVec, std::vector<std::vector<unsigned char>>& minipic){

    for(int i{0}, k{0}; i < hgt; i++){
        for(int j{0}; j < wdt; j++){
            minipic[i][j] = colorVec[k]; 
            k++;
        }
    }
}


std::vector<std::vector<unsigned char>> Resize::insertSubMatrix(std::vector<unsigned char>& colorVec, int scale){

    std::vector<unsigned char> tmp1(wdt*scale, 0);
    std::vector<std::vector<unsigned char>> copyColorVect(hgt*scale, tmp1);

    for (int i{}, k{}; k < colorVec.size() && i<copyColorVect.size(); i++) {
        for (int j{}; j < copyColorVect[i].size() && k < colorVec.size(); j++) {
            if (i >= wdt / 2) {
                if (wdt % 2 == 0) {
                    if (i <= copyColorVect[i].size() - (wdt / 2) - 1)
                        break;
                }
                else {
                    if (i <= copyColorVect[i].size() - (wdt / 2) - 2)
                        break;
                }
            }
            if (j < wdt / 2) {
                copyColorVect[i][j] = colorVec[k];
                k++;
            }
            if (wdt % 2 == 0) {
                if (j >= copyColorVect[i].size() - wdt / 2) {
                    copyColorVect[i][j] = colorVec[k];
                    k++;
                }
            }
            else {
                if (j >= copyColorVect[i].size() - (wdt / 2) - 1) {
                    copyColorVect[i][j] = colorVec[k];
                    k++;
                }
            }
        }
       
    }

    // for (int i{}; i < copyColorVect.size(); i++) {
    //     for (int j{}; j < copyColorVect[i].size(); j++) {
    //         std::cout << std::setw(5) << (short)copyColorVect[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return copyColorVect; 

}

void Resize::increaseSize(int scale){


    auto maxiPic = insertSubMatrix(blue, scale); 

    unsigned int size{wdt+1}; //unsigned int size{wdt+1}; 
    unsigned int bigSize{wdt*2}; //unsigned int bigSize{wdt+1*2}
    unsigned int bigSizeEndIndex{bigSize-2}; 
    unsigned int factor{bigSizeEndIndex-1}; 

    std::cout << size << std::endl; 


    if(size %2 == 0){
        //top row
        for(auto i{0}; i < floor(wdt/2); i++){
            for(auto j{2}; j <= size; j++){
            maxiPic[i][j] = (maxiPic[i][j-1] * (factor - j)/factor) + (maxiPic[i][factor+1] * (factor-(factor - j+1))/factor); 
            //std::cout << size << " " << factor << "\n";  }
        }

        //bottom row 
        for(auto i{bigSize-1}; i >= (bigSize - size/2); i--){
            for(auto j{floor(wdt/2)}; j <= size; j++){          
                maxiPic[i][j] = (maxiPic[i][j-1] * (factor - j)/factor) + (maxiPic[i][factor+1] * (factor-(factor - j+1))/factor); 
            }
        }

        // columns
        for(auto i{0}; i < bigSize; i++){
            for(auto j{floor(wdt/2)}; j < bigSize-size/2; j++){
                maxiPic[j][i] = (maxiPic[j-1][i] * (factor - j)/factor) + (maxiPic[factor+1][i] * (factor-(factor - j+1))/factor);  
            }
        } 


    } 

    //top row 
    for(auto i{0}; i < size/2; i++){
        for(auto j{size/2}; j <= 5; j++){
            maxiPic[i][j] = (maxiPic[i][j-1] * (factor - j)/factor) + (maxiPic[i][factor+1] * (factor-(factor - j+1))/factor); 
        }
    }

        //bottom row 
    for(auto i{bigSize-1}; i >= (bigSize - size/2); i--){
        for(auto j{size/2}; j <= factor; j++){          
            maxiPic[i][j] = (maxiPic[i][j-1] * (factor - j)/factor) + (maxiPic[i][factor+1] * (factor-(factor - j+1))/factor); 
        }
    }

    for(auto i{0}; i < bigSize; i++){
        for(auto j{size/2}; j < bigSize-size/2; j++){
           maxiPic[j][i] = (maxiPic[j-1][i] * (factor - j)/factor) + (maxiPic[factor+1][i] * (factor-(factor - j+1))/factor);  
        }
    } 



    // for (int i{}; i < maxiPic.size(); i++) {
    //     for (int j{}; j < maxiPic[i].size(); j++) {
    //         std::cout << std::setw(5) << (short)maxiPic[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    
    }

}



