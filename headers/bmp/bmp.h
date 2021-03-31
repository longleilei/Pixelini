#pragma once
#pragma pack(1) 
#include <vector> 

struct BITMAP_header
{
    char name[2];
    unsigned int size;
    int garbage;
    unsigned int image_offset; //offset from where image starts in file
};


struct DIB_header
{
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned short int colorplanes;
    unsigned short int bitsperpixel;
    unsigned int compression;
    unsigned int image_size;
};

 

class BMP {

    BITMAP_header header;
    DIB_header dibHeader; 
    
    std::vector<char> blue; 
    std::vector<char> green;
    std::vector<char> red;   
    
    std::unique_ptr<char[]> buffer; 

    
    void createPixelData(); 

public: 
    BMP(std::string fileName); 

    void readHeader(); 
    //hello

}; 