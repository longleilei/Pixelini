#include "files/writer.h"
#include <string>
#include <stdio.h>


Writer::Writer()=default; 

Writer& Writer::getInstance(){
    static Writer instance; 
    return instance;  
}


void Writer::writeToFile(std::string locToWrite, size_t size, std::unique_ptr<char[]> buffer){

    FILE * fp = fopen(locToWrite.c_str(), "w+");
    fwrite(buffer.get(), sizeof(char), size, fp);
    fclose(fp);
        
};