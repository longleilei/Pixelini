#pragma once 
#include <string>
#include<stdio.h>
#include <memory> 


class Writer{

    Writer(); 
     //hello
    

public: 
    static Writer& getInstance(); 
    void writeToFile(std::string locToWrite, size_t size, std::unique_ptr<char[]> buffer); 

}; 