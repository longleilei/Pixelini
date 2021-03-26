#include <string> 
#include <iostream>
#include <memory>

#include "files/loader.h" 
#include "bmp/bmp.h" 

BMP::BMP(std::string fileName){
    Loader& l = Loader::getInstance();
    buffer = l.getInstance().openFile(fileName);   
    readHeader();
}

void BMP::readHeader(){
    //char* h = new char[14]; //unique_ptr
    std::unique_ptr<char[]> h (new char[14]); 

    //check std::copy 
    for(int i{0}; i < 14; i++){
        h[i] = buffer.get()[i]; 
    }
    //header = *(BITMAP_header*)h; //reinterpret cast 
    header = *(reinterpret_cast<BITMAP_header*>(h)); 

    //delete[] h; 
    std::cout << header.name[0] << " " << header.name[1] << " " << header.size << " " 
    << header.image_offset << "/n";  

    //check for 4204
    if(header.name[0] != 'B' && header.name[1] != 'M'){
        std::cout << 'change file format'; 
    } 

    //define width and height 
    char* detailed_h = new char[40]; 

    for(int i{0}; i < 40; i++ ){
        detailed_h[i] = buffer.get()[i]; 
    }

    dibHeader = *(DIB_header*)detailed_h; 

    std::cout <<  " size: " << dibHeader.header_size << " " << "width: " << dibHeader.width << " " << "height: " << dibHeader.height << 
    " " << "colorplanes: " << dibHeader.colorplanes  << " " << "compression: "<< dibHeader.compression << " " 
    << "image size: " << dibHeader.image_size << "/n"; 

    delete[] detailed_h; 

    // //trying to get the pixel 
    // char* pixel = new char[3];

    // for(int i{header.image_offset}; i < (header.image_offset+3); i++){
    //     pixel = buffer.get()[i]; 
    // }

    // std::cout << "PIXEL: " << pixel << std::endl; 



}

