#include "files/writer.h"
#include <string>
#include <stdio.h>
#include <iostream>

Writer::Writer() = default;

Writer &Writer::getInstance()
{
  static Writer instance;
  return instance;
}

void Writer::writeToFile(std::string locToWrite, size_t size, const std::unique_ptr<unsigned char[]> &buffer)
{

  FILE *fp = fopen(locToWrite.c_str(), "wb+");
  if (fp == nullptr)
  {
    std::cout << " Failed to open file "
              << "\n";
    return;
  }

  fwrite(buffer.get(), sizeof(unsigned char), size, fp);
  fclose(fp);
};