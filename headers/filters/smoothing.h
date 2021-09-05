#pragma once
#include <vector>
#include "filters/filter.h"

class Smoothing: public Filter
{    
    double mask[3][3] = {
        {0.075, 0.125, 0.075},
        {0.125, 0.20, 0.125},
        {0.075, 0.125, 0.075}};

    double gaussianKernel[3][3] = {
        {0.3679, 0.6065, 0.3679},
        {0.6065, 1, 0.6065},
        {0.3679, 0.6065, 0.3679}};
    double gaussianKernel2[3][3] = {
        {0.001, 0.008, 0.001},
        {0.008, 1, 0.008},
        {0.001, 0.008, 0.001}};
    double gaussianKernel3[4][4] = {
        {1 / 16, 4 / 16, 4 / 16, 1 / 16},
        {1 / 16, 4 / 16, 4 / 16, 1 / 16},
        {1 / 16, 4 / 16, 4 / 16, 1 / 16},
        {1 / 16, 4 / 16, 4 / 16, 1 / 16}};

public:
    Smoothing(const std::vector<unsigned char> &_blue, const std::vector<unsigned char> &_green, const std::vector<unsigned char> &_red, unsigned int width, unsigned int height);

    void convertToGrayScale();

    void doSmoothing(std::vector<unsigned char> &colorVec);

    void gaussianBlur(std::vector<unsigned char> &colorVec);
    double **createKernel(double **input, int size);

};