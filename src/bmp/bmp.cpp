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
    std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset]) << "\n"; 
    std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset+1]) << "\n"; 
    std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset+2]) << "\n"; 


    for(int bl{0}; bl < pixelCount/4; bl++, i+=4){ 
        //blue[bl] = buffer.get()[i]; 
        //std::cout << static_cast<short>(buffer.get()[i]) << " "; 
        buffer.get()[i] = static_cast<char>(0x8f);  
    }

    i = header.image_offset+1; 

    for(int gr{0}; gr < pixelCount/4; gr++, i+=4 ){
        //blue[bl] = buffer.get()[i]; 
        buffer.get()[i] = static_cast<char>(0x8f); 
    }

    //i = header.image_offset+2; 

    // for(int r{0}; r < pixelCount/3; r++, i+=3 ){
    //     //blue[bl] = buffer.get()[i]; 
    //     buffer.get()[i] = 0; 
    // }

    
    Writer::getInstance().writeToFile("../result.bmp", header.size, std::move(buffer)); 

    
}

void BMP::readHeader(){
    
    std::unique_ptr<char[]> h (new char[14]); 

    //check std::copy 
    for(int i{0}; i < 14; i++){
        h[i] = buffer.get()[i]; 
    }
    header = *(reinterpret_cast<BITMAP_header*>(h.get())); 

    std::cout << header.name[0] << " " << header.name[1] << " " << header.size << " " 
    << header.image_offset << "\n";  

    //check for 4204
    if(header.name[0] != 'B' && header.name[1] != 'M'){
        std::cout << 'change file format'; 
    } 

    //define width and height 
    std::unique_ptr<char[]> detailed_h (new char[40]);  

    for(int i{0}, g{14}; i < 40; i++, g++ ){
        detailed_h[i] = buffer.get()[g]; 
        
    }

    dibHeader = *(reinterpret_cast<DIB_header*>(detailed_h.get())); 





}

