#pragma once 
#include <string>
#include<stdio.h>
#include <memory> 


class Loader{

    Loader(); 
    size_t calculateSize(FILE* resource); 
     //hello


public: 
    static Loader& getInstance(); 
    size_t bufferSize;  
    std::unique_ptr<char[]> openFile(std::string fileName); 

}; 

