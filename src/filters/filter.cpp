#include "filters/filter.h" 

Filter::Filter(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, 
const std::vector<unsigned char> &_red, unsigned int width, unsigned int height): wdt{width}, hgt{height}{

    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));
}

std::vector<unsigned char> Filter::getBlue() const { return blue; }
std::vector<unsigned char> Filter::getGreen() const { return green; }
std::vector<unsigned char> Filter::getRed() const { return red; }