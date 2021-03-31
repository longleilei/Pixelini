#include <string> 
#include <iostream>
#include <memory>

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

    for(int i{0}; i < dibHeader.width; i++){ 
        for(int j{0}; j < dibHeader.height; j+=3){
            buffer.get()[header.image_offset + j] = 255; 
            // std::cout << "i: " << i << "j: " << j << " colorData: " 
            // << colorData[i * dibHeader.width + j] << std::endl;   
        }
        
    }
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

