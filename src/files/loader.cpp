#include "files/loader.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "files/exception.h"

Loader::Loader():resource{nullptr}, buffer{nullptr}; 

Loader& Loader::getInstance(){
    static Loader instance; 
    return instance;  
}


size_t Loader::calculateSize()
{

    fseek(resource.get(), 0L, SEEK_END);
    auto sz = ftell(resource.get());
    //go back to the beginning
    fseek(resource.get(), 0L, SEEK_SET);
    return sz;
}

const char *Loader::getBuffer()
{
    return buffer.get();
}

void Loader::openFile(std::string fileName){

    location = fileName; 
    std::unique_ptr<FILE, void(*)(FILE*)> res{fopen(fileName.c_str(), "r+"), [](FILE *file) { fclose(file); }}; 
    resource.reset(std::move(res)); 

    if (resource != nullptr)
    {
        std::cout << "file opened " << std::endl;
        fillBuffer();
        return;
    }

    Excptn pathError{"error open file"}; 
    pathError.setPath(fileName); 
    throw pathError; 
}

void Loader::fillBuffer()
{
    auto size{calculateSize()};
    char *b{new char[size]};
    fread(b, sizeof(char), size, resource.get());
    buffer.reset(std::move(b));
}
