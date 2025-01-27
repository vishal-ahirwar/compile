#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <vector>

class Utility
{
public:
    static bool isThisInputFile(const std::string &file);
    static bool compileTheseFiles(const std::vector<std::string> &files);
};
#endif