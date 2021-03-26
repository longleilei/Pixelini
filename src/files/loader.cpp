#include "files/loader.h"
#include <string>
#include <stdio.h>
#include "files/exception.h"

Loader::Loader() = default; 

Loader& Loader::getInstance(){
    static Loader instance; 
    return instance;  
}


size_t Loader::calculateSize( FILE* resource )
{

    fseek(resource, 0L, SEEK_END);
    auto sz = ftell(resource);
    //go back to the beginning
    fseek(resource, 0L, SEEK_SET);
    bufferSize = sz; 
    return sz;
}



std::unique_ptr<char[]> Loader::openFile(std::string fileName){

    
    std::unique_ptr<FILE, void(*)(FILE*)> res{fopen(fileName.c_str(), "r+"), [](FILE *file) { fclose(file); }}; 

    if (res != nullptr)
    {
        auto size{calculateSize(res.get())};
        std::unique_ptr<char[]>b{new char[size]};
        fread(b.get(), sizeof(char), size, res.get());
        return b;
    }

    Excptn pathError{"error open file"}; 
    pathError.setPath(fileName); 
    throw pathError; 

    
}


