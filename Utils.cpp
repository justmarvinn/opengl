#include "Utils.h"

std::string Utils::ParseText(const char* filename)
{
    std::ifstream file;
    file.open(filename);
    std::string res = "";

    if (!file) {
        std::cerr << "Can not open file" << std::endl;
    } else {
        std::string line;
        while (std::getline(file, line)) 
            res += line + "\n";        
    }
    file.close();
    return res;
}

std::string Utils::ParseFormat(std::string filename) 
{
    if (filename.find(".") != std::string::npos)
        return filename.substr(filename.find_last_of("."));
    else {
        std::cerr << "File does not have an extension" << std::endl;
        return "";
    }
}