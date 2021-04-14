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
    const int pixelCount = header.size - header.image_offset; 

    std::cout << "size: " << pixelCount << " w*h: " << (dibHeader.width * dibHeader.height) << std::endl; 

    auto offset = header.image_offset;
    uint32_t channels = dibHeader.bitsperpixel / 8;
    for (int i{}; i < pixelCount; i++) {
        pixels.push_back(buffer.get()[offset + i]);
    }
    for (int i{}; i < dibHeader.height; i++) {
        for (int j{}; j < dibHeader.width*channels; j++) {
            blue.push_back(pixels[channels * (i * dibHeader.width + j)]);
            green.push_back(pixels[channels * (i * dibHeader.width + j) + 1]);
            red.push_back(pixels[channels * (i * dibHeader.width + j) + 2]);
        }
    }

    
    for(int i{}; i < pixelCount; i++){
        buffer.get()[offset+i] = pixels[i]; 
    }

    Writer::getInstance().writeToFile("../assets/result.bmp", header.size, buffer);  

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
        std::cout << "change file format"; 
    } 

    
    std::unique_ptr<char[]> detailed_h (new char[40]);  

    for(int i{0}, g{14}; i < 40; i++, g++ ){
        detailed_h[i] = buffer.get()[g]; 
        
    }

    dibHeader = *(reinterpret_cast<DIB_header*>(detailed_h.get())); 





}

