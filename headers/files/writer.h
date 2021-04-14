#pragma once 
#include <string>
#include<stdio.h>
#include <memory> 


class Writer{

    Writer(); 
    

public: 
    static Writer& getInstance(); 
    void writeToFile(std::string locToWrite, size_t size, const std::unique_ptr<char[]>& buffer); 

}; 