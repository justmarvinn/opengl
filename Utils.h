#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace Utils
{
    std::string ParseText(const char* filename);
    std::string ParseFormat(std::string filename);
}