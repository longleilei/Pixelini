#include "files/loader.h"
#include "files/writer.h"
#include <iostream>
#include "files/exception.h"
#include "bmp/bmp.h"

int main(){
    std::string name{"../assets/land.bmp"}; 
    std::string copy{"../assets/forWrite.bmp"}; 
    
    try{
        

        BMP bmp{name}; 
       
        
    } catch(Excptn& errorPath){
        std::cout<< errorPath.what() << " " << errorPath.getPath()<<std::endl; 
    }

    
    
    
    
}