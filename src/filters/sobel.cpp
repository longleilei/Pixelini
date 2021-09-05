#include <iostream>
#include "filters/sobel.h" 
#include <cmath>
#include <numeric>
#include <iomanip>

Sobel::Sobel(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
const std::vector<unsigned char> &_red, unsigned int width, unsigned int height ): Filter{_blue, _green, _red, width, height}{

    //std::cout << "begin blue" << std::endl; 
    enchanceEdges(blue);
    //std::cout << "begin green" << std::endl; 
    enchanceEdges(green);
    //std::cout << "begin red" << std::endl; 
    enchanceEdges(red);
}


std::vector<unsigned int> Sobel::getGradVect(){
    return gradVect; 
}

std::vector<std::vector<unsigned int>> Sobel::createGradMatrix(){

    std::vector<unsigned int> tmp1(wdt, 0);
    std::vector<std::vector<unsigned int>> gradMatrix(hgt, tmp1);

    for(int i{0}, k{0}; i < hgt; i++ ){
        for(int j{0}; j< wdt; j++){
            gradMatrix[i][j] = gradVect[k];
            k++;                     
        }
        k++;
    }

    return gradMatrix; 
}

void Sobel::enchanceEdges(std::vector<unsigned char>& colorVec){

    int pad_rows = (hgt)/2+1; 
    int pad_cols = (wdt)/2+1;

    // std::cout << "Before everything" << " " << std::endl; 
    // for(auto& x: colorVec ){
    //     std::cout << (short) x << " "; 
    // }
    // std::cout << std::endl; 

    std::vector<unsigned char> tmp1((wdt + (2 * pad_cols)), 0);
    std::vector<std::vector<unsigned char>> copyColorVect((hgt + (2 * pad_rows)), tmp1);

    for(int i{pad_rows}, k{0}; i < (pad_rows + hgt); i++ ){
        for(int j{pad_cols}; j< (pad_cols + wdt); j++){
            copyColorVect[i][j] = colorVec[k];
            k++;                     
        }
    }

    std::vector<unsigned char> tmp2((wdt + (2 * pad_cols)), 0);
    std::vector<std::vector<unsigned char>> copyColorVect2((hgt + (2 * pad_rows)), tmp2);

    for(int i{pad_rows}, k{0}; i < (pad_rows + hgt); i++ ){
        for(int j{pad_cols}; j< (pad_cols + wdt); j++){
            copyColorVect2[i][j] = colorVec[k];
            k++;                     
        }
    }

    //applying horizontal Sobel 
    for (int v{pad_rows}; v < (pad_rows + hgt); v++){
        for (int u{pad_cols}; u < (pad_cols + wdt); u++){
            double sum = 0; 
            for(int j{-1}; j < 2; j++){
                for(int i{-1}; i< 2; i++){ 
                    auto p = copyColorVect2[v][u];
                    double c = horizontalSobel[j+1][i+1]; 
                    sum = c * p; 
                    copyColorVect[v][u] = sum; 
                    //std::cout << "p= " << (short) p << " c= " << c << " sum= " << sum << std::endl; 

                }
            }
            //colorVect[v][u] = sum;  
            //std::cout << "copyColorVect[v][u]= " <<copyColorVect[v][u] << " ";  
        }
    }



    //applying vertical Sobel 
    for (int v{pad_rows}; v < (pad_rows + hgt); v++){
        for (int u{pad_cols}; u < (pad_cols + wdt); u++){
            double sum = 0; 
            for(int j{-1}; j < 2; j++){
                for(int i{-1}; i< 2; i++){ 
                    auto p = copyColorVect2[v][u];
                    double c = verticalSobel[j+1][i+1]; 
                    sum = c * p; 
                    copyColorVect[v][u] = sum;
                    //std::cout << "p= " << (short) p << " c= " << c << " sum= " << sum << std::endl;
                    //std::cout << "sum= " << sum << " "; 
                }
            }
            // std::cout << copyColorVect[v][u] << " ";
            
        }
    }


    


    //double theta{}; 
    //take our image and calculate neightborhood 
    for (int v{pad_rows}, k{}; v < (pad_rows + hgt-1); v++){
        for (int u{pad_cols}; u < (pad_cols + wdt-1); u++){
            int grad = 0; 
            
                int Gx = abs((copyColorVect[v-1][u+1] + (2 * copyColorVect[v][u+1]) + copyColorVect[v+1][u+1]) 
                                - (copyColorVect[v-1][u-1] + (2 * copyColorVect[v][u-1]) + copyColorVect[v+1][u-1])); 

                // std::cout << "Gx = " << Gx << std::endl;

                //GxVec.push_back(Gx); 
                int Gy = abs((copyColorVect[v-1][u-1] + (2 * copyColorVect[v-1][u]) + copyColorVect[v-1][u+1]) 
                                - (copyColorVect[v+1][u-1] + (2 * copyColorVect[v+1][u]) + copyColorVect[v+1][u+1]));
                //GyVec.push_back(Gx); 

                // std::cout << "Gy = " << Gy << std::endl;

                

                grad = Gx > Gy ? Gx : Gy; 
                if(grad > 255) grad = 255;
                gradVect.push_back(grad); 
                colorVec[k] = static_cast<unsigned char>(grad);
                k++;  
        }
        k++; 
    }


    
    
}
