#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "files/loader.h"
#include "files/writer.h"
#include "bmp/bmp.h"

BMP::BMP(std::string fileName)
{
    buffer = Loader::getInstance().openFile(fileName);
    readHeader();
    createPixelData();
}

unsigned int BMP::getWidth(){
    return dibHeader.width; 
} 

unsigned int BMP::getHeight(){
    return dibHeader.height;
}

void BMP::writeImg(int offset, int pixelCount)
{

    for (int i{}; i < pixelCount; i++)
    {
        buffer.get()[offset + i] = pixels[i];
    }

    Writer::getInstance().writeToFile("../assets/result.bmp", header.size, buffer);
}

std::vector<char> BMP::getBlue()
{
    return blue;
}
std::vector<char> BMP::getGreen()
{
    return green;
}
std::vector<char> BMP::getRed()
{
    return red;
}

void BMP::createPixelData()
{
    const int pixelCount = header.size - header.image_offset;

    std::cout << "size: " << pixelCount << " w*h: " << (dibHeader.width * dibHeader.height) << std::endl;

    auto offset = header.image_offset;

    uint32_t channels = dibHeader.bitsperpixel / 8;

    for (int i{}; i < pixelCount; i++)
    {
        pixels.push_back(buffer.get()[offset + i]);
    }
    for (int i{}; i < dibHeader.height; i++)
    {
        for (int j{}; j < dibHeader.width * channels; j++)
        {
            blue.push_back(pixels[channels * (i * dibHeader.width + j)]);
            green.push_back(pixels[channels * (i * dibHeader.width + j) + 1]);
            red.push_back(pixels[channels * (i * dibHeader.width + j) + 2]);
        }
    }

    //writeImg(offset, pixelCount);
}

void BMP::setColors(const std::vector<char> &bl, const std::vector<char> &gr, const std::vector<char> &re)
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

    for (int i{}, k{}; i < dibHeader.height; i++)
    {
        for (int j{}; j < dibHeader.width * channels; j++)
        {
            pixels[channels * (i * dibHeader.width + j)] = blue[k];
            pixels[channels * (i * dibHeader.width + j) + 1] = green[k];
            pixels[channels * (i * dibHeader.width + j) + 2] = red[k];
            k++;
        }
    }

    writeImg(offset, pixelCount);
}

void BMP::readHeader()
{

    std::unique_ptr<char[]> h(new char[14]);

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

    std::unique_ptr<char[]> detailed_h(new char[40]);

    for (int i{0}, g{14}; i < 40; i++, g++)
    {
        detailed_h[i] = buffer.get()[g];
    }

    dibHeader = *(reinterpret_cast<DIB_header *>(detailed_h.get()));
}
