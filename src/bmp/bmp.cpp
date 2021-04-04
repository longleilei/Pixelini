#include <string> 
#include <iostream>
#include <memory>
#include <vector>

#include "files/loader.h" 
#include "files/writer.h" 
#include "bmp/bmp.h" 

BMP::BMP(std::string fileName){
    Loader& l = Loader::getInstance();
    buffer = l.getInstance().openFile(fileName);   
    readHeader();
    createPixelData(); 
}

void BMP::createPixelData(){
    int pixelCount = header.size - header.image_offset; 
    size_t i{header.image_offset}; 
    // std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset]) << "\n"; 
    // std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset+1]) << "\n"; 
    // std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset+2]) << "\n"; 


    //char* colorData = &(buffer.get()[header.image_offset]); 

    std::vector<uint8_t>pixels; 

    std::cout << "before pixels loop" << std::endl; 

    for(int i{0}; i < 3 * dibHeader.width*dibHeader.height; i++){
        pixels.push_back(buffer.get()[header.image_offset+i]); 
    }

    std::cout << "before 1st loop" << std::endl; 

    for(int i{0}; i < dibHeader.height; i++){ 
        for(int j{0}; j < dibHeader.width; j++){
            pixels[3 * (i * dibHeader.width + (j+1)) ] = 0; 
      
        }  
    }
    std::cout << "buffer loop" << std::endl; 

    for(int i{0}; i < 3 * dibHeader.width*dibHeader.height; i++){
        buffer.get()[header.image_offset + i] = pixels[i]; 
    }

    std::cout << "after loop" << std::endl; 

    Writer::getInstance().writeToFile("../result.bmp", header.size, std::move(buffer)); 

    
}

void BMP::readHeader(){
    
    std::unique_ptr<char[]> h (new char[14]); 

    
    for(int i{0}; i < 14; i++){
        h[i] = buffer.get()[i]; 
    }
    header = *(reinterpret_cast<BITMAP_header*>(h.get())); 

    std::cout << header.name[0] << " " << header.name[1] << " " << header.size << " " 
    << header.image_offset << "\n";  

    
    if(header.name[0] != 'B' && header.name[1] != 'M'){
        std::cout << 'change file format'; 
    } 

    
    std::unique_ptr<char[]> detailed_h (new char[40]);  

    for(int i{0}, g{14}; i < 40; i++, g++ ){
        detailed_h[i] = buffer.get()[g]; 
        
    }

    dibHeader = *(reinterpret_cast<DIB_header*>(detailed_h.get())); 





}

