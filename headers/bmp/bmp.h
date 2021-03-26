#pragma once
#pragma pack(1) 

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

struct RGB {
    unsigned char blue; 
    unsigned char green; 
    unsigned char red; 
}; 

class BMP {

    BITMAP_header header;
    DIB_header dibHeader; 
    RGB color; 
    std::unique_ptr<char[]> buffer; 

public: 
    BMP(std::string fileName); 

    void readHeader(); 




}; 