#pragma once 
#include <string>
#include<stdio.h>
#include <memory>
#include <exception> 
#include <string> 

class Excptn : public std::exception {
    std::string path; 
    std::string message;  
public: 
    
    Excptn(std::string msg);

    const char* what() const noexcept override;

    std::string getPath();

    void setPath(std::string path); 

    ~Excptn() = default; 
   
};