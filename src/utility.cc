#include <utility.h>
#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
constexpr const char *extentions[]{".cpp", ".cxx", ".cc"};
constexpr int ESIZE{sizeof(extentions) / sizeof(extentions[0])};

bool Utility::isThisInputFile(const std::string &file)
{
    for (int i = 0; i < ESIZE; ++i)
    {
        auto index = file.find(extentions[i]);
        if (index != std::string::npos)
        {
            return true;
        };
    };
    return false;
};
bool Utility::compileTheseFiles(const std::vector<std::string> &files)
{
    std::string c_files{};
    std::string compile_command{"g++ "};
    for (const auto &file : files)
    {
        c_files += (" \"" + file + "\"");
    };
    compile_command += c_files;
    return system(compile_command.c_str()) == 0;
}
void Utility::log(const std::string_view &msg, Log msg_type)
{
    switch (msg_type)
    {
    case Log::E_DISPLAY:
    {
        fmt::print(fmt::emphasis::faint, "{}", msg.data());
        break;
    };
    case Log::E_ERROR:
    {
        fmt::print(fmt::emphasis::faint | fmt::fg(fmt::color::crimson), "{}", msg.data());
        break;
    };
    case Log::E_WARNING:
    {
        fmt::print(fmt::emphasis::faint | fmt::fg(fmt::color::green), "{}", msg.data());
        break;
    };
    }
};