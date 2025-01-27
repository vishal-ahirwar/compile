#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <vector>

class Utility
{
public:
    enum class Log
    {
        E_DISPLAY,
        E_WARNING,
        E_ERROR
    };

public:
    static bool isThisInputFile(const std::string &file);
    static bool compileTheseFiles(const std::vector<std::string> &files);
    static void log(const std::string_view &msg, Log);
};
#endif