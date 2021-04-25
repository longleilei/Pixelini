#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

#include "filters/histogram.h"

Histogram::Histogram(const std::vector<char> &_blue, const std::vector<char> &_green, const std::vector<char> &_red)
{

    std::copy(_blue.begin(), _blue.end(), std::back_inserter(blue));
    std::copy(_green.begin(), _green.end(), std::back_inserter(green));
    std::copy(_red.begin(), _red.end(), std::back_inserter(red));

    fillHistogram();
    normalizeColorValue(blue, blueHist);
    normalizeColorValue(green, greenHist);
    normalizeColorValue(red, redHist);
}

void Histogram::normalizeColorValue(std::vector<char> &color, std::map<unsigned char, int> &hist)
{

    auto numOfPixels{std::accumulate(hist.begin(), hist.end(), 0, [](int val, std::map<unsigned char, int>::value_type &hist) { return val + hist.second; })};
    constexpr int prediction{7};

    std::vector<double> colorPDF;
    for (int i{0}; i < hist.size(); i++)
    {
        colorPDF.push_back(static_cast<double>(hist[i]) / hist.size());
    }

    std::vector<double> colorCDF;
    colorCDF.push_back(colorPDF[0]);
    for (int i{1}; i < hist.size(); i++)
    {
        colorCDF.push_back(colorPDF[i] + colorPDF[i - 1]);
    }

    // for(int i{0}; i < 500; i++){
    //     std::cout << colorCDF[i] << " ";
    // }

    std::vector<double> colorScale;
    for (int i{0}; i < hist.size(); i++)
    {
        colorScale.push_back(colorCDF[i] * prediction);
    }

    for (int i{0}; i < 50; i++)
    {
        std::cout << static_cast<short>(color[i]) << " ";
    }

    std::cout << std::endl;

    for (int i{0}; i < colorScale.size(); i++)
    {
        std::replace(color.begin(), color.end(), i, static_cast<int>(round(colorScale[i])));
    }

    for (int i{0}; i < 50; i++)
    {
        std::cout << static_cast<short>(color[i]) << " ";
    }
}

void Histogram::fillHistogram()
{

    for (int i{0}; i < blue.size(); i++)
    {
        blueHist[blue[i]]++;
    }

    for (int i{0}; i < green.size(); i++)
    {
        greenHist[green[i]]++;
    }

    for (int i{0}; i < red.size(); i++)
    {
        redHist[red[i]]++;
    }

    // int calibre{255};
    // std::vector<double> bluePDF;
    // for (int i{}; i < blueHist.size(); i++)
    // {
    //     bluePDF.push_back(static_cast<double>(blueHist[i]) / blue.size());
    // }
    // std::vector<double> blueCDF;
    // for (int i{}; i < blueHist.size(); i++)
    // {
    //     if (i == 0)
    //     {
    //         blueCDF.push_back(bluePDF[i]);
    //         continue;
    //     }
    //     blueCDF.push_back(bluePDF[i] + bluePDF[i - 1]);
    // }

    // std::vector<double> scale{};
    // for (int i{}; i < blueHist.size(); i++)
    // {
    //     scale.push_back(blueCDF[i] * calibre);
    // }

    // for (int i{}; i < scale.size(); i++)
    // {
    //     std::replace(blue.begin(), blue.end(), i, static_cast<int>(round(scale[i])));
    // }

    // std::vector<double> redPDF;
    // for (int i{}; i < redHist.size(); i++)
    // {
    //     redPDF.push_back(static_cast<double>(redHist[i]) / red.size());
    // }
    // std::vector<double> redCDF;
    // for (int i{}; i < redHist.size(); i++)
    // {
    //     if (i == 0)
    //     {
    //         redCDF.push_back(redPDF[i]);
    //         continue;
    //     }
    //     redCDF.push_back(redPDF[i] + redPDF[i - 1]);
    // }

    // std::vector<double> redscale{};
    // for (int i{}; i < redHist.size(); i++)
    // {
    //     redscale.push_back(redCDF[i] * calibre);
    // }

    // for (int i{}; i < redscale.size(); i++)
    // {
    //     std::replace(red.begin(), red.end(), i, static_cast<int>(round(redscale[i])));
    // }

    // std::vector<double> greenPDF;
    // for (int i{}; i < greenHist.size(); i++)
    // {
    //     greenPDF.push_back(static_cast<double>(greenHist[i]) / green.size());
    // }
    // std::vector<double> greenCDF;
    // for (int i{}; i < greenHist.size(); i++)
    // {
    //     if (i == 0)
    //     {
    //         greenCDF.push_back(greenPDF[i]);
    //         continue;
    //     }
    //     greenCDF.push_back(greenPDF[i] + redPDF[i - 1]);
    // }

    // std::vector<double> greenscale{};
    // for (int i{}; i < greenHist.size(); i++)
    // {
    //     greenscale.push_back(greenCDF[i] * calibre);
    // }

    // for (int i{0}; i < 50; i++)
    // {
    //     std::cout << static_cast<short>(green[i]) << " ";
    // }

    // std::cout << std::endl;

    // for (int i{}; i < greenscale.size(); i++)
    // {
    //     std::replace(green.begin(), red.end(), i, static_cast<int>(round(greenscale[i])));
    // }

    // for (int i{0}; i < 50; i++)
    // {
    //     std::cout << static_cast<short>(green[i]) << " ";
    // }
}

std::vector<char> Histogram::getBlue() const { return blue; }
std::vector<char> Histogram::getGreen() const { return green; }
std::vector<char> Histogram::getRed() const { return red; }
