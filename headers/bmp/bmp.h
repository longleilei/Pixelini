#pragma once
#pragma pack(1)
#include <vector>

struct BITMAP_header
{
    unsigned char name[2];
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

class BMP
{

    BITMAP_header header;
    DIB_header dibHeader;

    std::vector<unsigned char> blue;
    std::vector<unsigned char> green;
    std::vector<unsigned char> red;

    std::unique_ptr<unsigned char[]> buffer;

    void createPixelData();

public:
    std::vector<uint8_t> pixels;
    BMP(std::string fileName);

    std::vector<unsigned char> getBlue();
    std::vector<unsigned char> getGreen();
    std::vector<unsigned char> getRed();

    void readHeader();

    void writeImg(int offset, int pixelCount);

    void setColors(const std::vector<unsigned char> &blue, const std::vector<unsigned char> &green, const std::vector<unsigned char> &red);

    unsigned int getWidth();
    unsigned int getHeight();
    unsigned int getOffcet();
};