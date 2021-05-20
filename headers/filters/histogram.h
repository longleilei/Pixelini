#pragma once
#include <vector>
#include <map>

class Histogram
{

    std::vector<unsigned char> blue;
    std::vector<unsigned char> green;
    std::vector<unsigned char> red;
    std::map<unsigned unsigned char, int> redHist;
    std::map<unsigned unsigned char, int> greenHist;
    std::map<unsigned unsigned char, int> blueHist;

    void fillHistogram();
    void normalizeColorValue(std::vector<unsigned char> &color, std::map<unsigned unsigned char, int> &hist);

public:
    Histogram(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, const std::vector<unsigned char> &_red);

    std::vector<unsigned char> getBlue() const;
    std::vector<unsigned char> getGreen() const;
    std::vector<unsigned char> getRed() const;
};
