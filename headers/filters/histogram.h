#pragma once
#include <vector>
#include <map>

class Histogram
{

    std::vector<char> blue;
    std::vector<char> green;
    std::vector<char> red;
    std::map<unsigned char, int> redHist;
    std::map<unsigned char, int> greenHist;
    std::map<unsigned char, int> blueHist;

    void fillHistogram();
    void normalizeColorValue(std::vector<char> &color, std::map<unsigned char, int> &hist);

public:
    Histogram(const std::vector<char> &_blue, const std::vector<char> &_green, const std::vector<char> &_red);

    std::vector<char> getBlue() const;
    std::vector<char> getGreen() const;
    std::vector<char> getRed() const;
};
