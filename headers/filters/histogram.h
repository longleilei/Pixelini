#pragma once
#include <vector>
#include <map>
#include "filters/filter.h"

class Histogram : public Filter
{
    std::map<unsigned char, int> redHist;
    std::map<unsigned char, int> greenHist;
    std::map<unsigned char, int> blueHist;

    void fillHistogram();
    void normalizeColorValue(std::vector<unsigned char> &color, std::map<unsigned char, int> &hist);

public:
    Histogram(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, const std::vector<unsigned char> &_red);

};
