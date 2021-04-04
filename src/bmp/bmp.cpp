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
    const int pixelCount = header.size - 54; 
    size_t i{header.image_offset}; 
    // std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset]) << "\n"; 
    // std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset+1]) << "\n"; 
    // std::cout << std::hex << static_cast<unsigned int>(buffer.get()[header.image_offset+2]) << "\n"; 

    //data[3 * (i * width + j)]

    //char* colorData = &(buffer.get()[header.image_offset]); 
    auto offset = header.image_offset;
    uint32_t channels = dibHeader.bitsperpixel / 8;
    std::cout << dibHeader.width << std::endl;
    std::cout << dibHeader.height << std::endl;
    std::vector<uint8_t> pixels;
    for (int i{}; i < 3* dibHeader.height * dibHeader.width; i++) {
        pixels.push_back(buffer.get()[offset + i]);
    }
    for (int i{}; i < dibHeader.height; i++) {
        for (int j{}; j < dibHeader.width; j++) {
            pixels[channels * (i * dibHeader.width + j)+2] = 0;
            pixels[channels * (i * dibHeader.width + j) + 1] = 0;
        }
    }
    for (int i{}; i < 3 * dibHeader.height * dibHeader.width; i++) {
        buffer.get()[offset + i] = pixels[i];
    }

        std::cout << pixels.size() << " ";

    Writer::getInstance().writeToFile("../assets/result.bmp", header.size, std::move(buffer)); 

    
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

