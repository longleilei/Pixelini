#include "files/exception.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

Excptn::Excptn(std::string msg) : message{msg} {}

const char *Excptn::what() const noexcept
{
    return message.c_str();
}

std::string Excptn::getPath()
{
    return path;
}

void Excptn::setPath(std::string _path)
{
    path = _path;
}