#pragma once 
#include <string>
#include<stdio.h>
#include <memory> 


class Loader{

    std::string location{}; 
    std::unique_ptr<FILE, void(*)(FILE*)> resource;
    std::unique_ptr<char[]> buffer;   
    Loader(); 
    

public: 
    static Loader& getInstance(); 

    size_t calculateSize(); 

    const char* getBuffer();

    void fillBuffer(); 

    void openFile(std::string fileName); 

}; 

