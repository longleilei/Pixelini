#include "files/writer.h"
#include <string>
#include <stdio.h>
#include <iostream> 


Writer::Writer()=default; 

Writer& Writer::getInstance(){
    static Writer instance; 
    return instance;  
}


void Writer::writeToFile(std::string locToWrite, size_t size, std::unique_ptr<char[]> buffer){

    FILE * fp = fopen(locToWrite.c_str(), "w+");
    if(fp == nullptr){
      std::cout << " Failed to open file " << "\n"; 
      return;   
    }

    fwrite(buffer.get(), sizeof(char), size, fp);
    fclose(fp);
        
};