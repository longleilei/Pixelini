#include "files/loader.h"
#include <iostream>
#include "files/exception.h"

int main(){
    std::string name{"../assets/land.bmp"}; 
    //std::string name{"1234"}; 
    try{
        //Loader l{name}; 
        Loader& l = Loader::getInstance(); 
        l->calculateSize(); 
        
    } catch(Excptn& errorPath){
        std::cout<< errorPath.what() << " " << errorPath.getPath()<<std::endl; 
    }

    std::cout << sizeof(Loader) <<std::endl; 
    
    
    
}