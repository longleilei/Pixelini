#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

#include "files/loader.h"
#include "files/writer.h"
#include "bmp/bmp.h"

BMP::BMP(std::string fileName)
{
    buffer = Loader::getInstance().openFile(fileName);
    readHeader();
    createPixelData();
}

unsigned int BMP::getWidth()
{
    return dibHeader.width;
}

unsigned int BMP::getHeight()
{
    return dibHeader.height;
}

unsigned int BMP::getOffcet()
{
    return header.image_offset;
}

void BMP::writeImg(int offset, int pixelCount)
{

    for (int i{}; i < pixelCount-1; i++)
    {
        buffer.get()[offset + i] = pixels[i];
    }

    Writer::getInstance().writeToFile("../assets/result1.bmp", header.size, buffer);
}

void BMP::saveImg( size_t wdt, size_t hgt, const std::vector<unsigned char> &bl, 
const std::vector<unsigned char> &gr, const std::vector<unsigned char> &re)
{

    setColors(bl, gr, re); 
    const int pixelCount = header.size - header.image_offset-1;
    auto offset = header.image_offset;
    auto size{ bl.size() + gr.size() + re.size()}; 

    //std::cout<< "size " << size << " header size "<< header.size << " pixelCount " << (header.size - pixelCount) << std::endl; 

    // if (size == pixelCount){
    //     writeImg(offset, pixelCount); 
    //     return; 
    // }

    // std::cout<< "pixelCount " << pixelCount << " header size "<< header.size <<std::endl; 

    // header.size -= pixelCount; 
    // header.size += size; 
    // dibHeader.width = wdt; 
    // dibHeader.height = hgt;

    // std::cout<<" header size "<< header.size << std::endl; 

    writeImg(offset, size); 
    //writeHeader();






}


std::vector<unsigned char> BMP::getBlue()
{
    return blue;
}
std::vector<unsigned char> BMP::getGreen()
{
    return green;
}
std::vector<unsigned char> BMP::getRed()
{
    return red;
}

void BMP::createPixelData()
{
    const int pixelCount = header.size - header.image_offset-1;

    std::cout << "size: " << pixelCount << " w*h: " << (dibHeader.width * dibHeader.height) << std::endl;

    auto offset = header.image_offset;

    uint32_t channels = dibHeader.bitsperpixel / 8;

   std::cout << "creating pixel vector" << std::endl; 

    for (int i{}; i < pixelCount; i++)
    {
        pixels.push_back(buffer.get()[offset + i]);
    }

    std::cout << "creating color vectors" << std::endl; 


    for (int i{}; i < pixelCount-2; i+=dibHeader.width%4) {
        for (int j{}; j < dibHeader.width && i < pixelCount - 2; j++, i+=3) {
            blue.push_back(pixels[i]);
            green.push_back(pixels[i + 1]);
            red.push_back(pixels[i + 2]);
        }
        
    }

    std::cout << "finish creating color vectors" << std::endl; 

}

void BMP::setColors(const std::vector<unsigned char> &bl, const std::vector<unsigned char> &gr, const std::vector<unsigned char> &re)
{

    const int pixelCount = header.size - header.image_offset;
    auto offset = header.image_offset;
    uint32_t channels = dibHeader.bitsperpixel / 8;

    blue.clear();
    green.clear();
    red.clear();

    std::copy(bl.begin(), bl.end(), std::back_inserter(blue));
    std::copy(gr.begin(), gr.end(), std::back_inserter(green));
    std::copy(re.begin(), re.end(), std::back_inserter(red));

    for (int i{}, k{}; i < pixelCount-2; i += dibHeader.width % 4) {
        for (int j{}; j < dibHeader.width && i < pixelCount - 3; j++, i += 3) {
            pixels[i] = blue[k];
            pixels[i + 1] = green[k];
            pixels[i + 2] = red[k];
            k++;
        }

    }

    //writeImg(offset, pixelCount);
}


void BMP::writeHeader()
{


    std::unique_ptr<unsigned char[]> h(new unsigned char[14]);

    auto headerPtr{reinterpret_cast<unsigned char*>(&header)}; 
    auto headerVec{std::vector<unsigned char>(headerPtr, headerPtr + sizeof header)};
    
    std::copy(headerVec.begin(), headerVec.end(), std::ostream_iterator<short>(std::cout, " "));


    for (int i{0}; i < 14; i++)
    {
        h[i] = buffer.get()[i];
    }
    header = *(reinterpret_cast<BITMAP_header *>(h.get()));

    std::cout << header.name[0] << " " << header.name[1] << " " << header.size << " "
              << header.image_offset << "\n";

    if (header.name[0] != 'B' && header.name[1] != 'M')
    {
        std::cout << "change file format";
    }

    std::unique_ptr<unsigned char[]> detailed_h(new unsigned char[40]);

    for (int i{0}, g{14}; i < 40; i++, g++)
    {
        detailed_h[i] = buffer.get()[g];
    }

    // dibHeader = *(reinterpret_cast<DIB_header *>(detailed_h.get()));
}

void BMP::readHeader()
{

    std::unique_ptr<unsigned char[]> h(new unsigned char[14]);

    for (int i{0}; i < 14; i++)
    {
        h[i] = buffer.get()[i];
    }
    header = *(reinterpret_cast<BITMAP_header *>(h.get()));

    std::cout << header.name[0] << " " << header.name[1] << " " << header.size << " "
              << header.image_offset << "\n";

    if (header.name[0] != 'B' && header.name[1] != 'M')
    {
        std::cout << "change file format";
    }

    std::unique_ptr<unsigned char[]> detailed_h(new unsigned char[40]);

    for (int i{0}, g{14}; i < 40; i++, g++)
    {
        detailed_h[i] = buffer.get()[g];
    }

    dibHeader = *(reinterpret_cast<DIB_header *>(detailed_h.get()));
}
