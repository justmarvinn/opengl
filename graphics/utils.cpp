#include "utils.h"

std::string utils::parseText(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    std::string res = "";

    if (!file)
        std::cerr << "Can not open file " << filename << std::endl;
    else {
        std::string line;
        while (std::getline(file, line)) 
            res += line + '\n'; 
    }
    file.close();
    return res + '\0';
}

std::string utils::parseFormat(std::string filename) 
{
    if (filename.find(".") != std::string::npos)
        return filename.substr(filename.find_last_of("."));
    else {
        std::cerr << "File does not have an extension" << std::endl;
        return "";
    }
}
