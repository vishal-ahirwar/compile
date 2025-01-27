#include <utility.h>
#include <iostream>
constexpr char *extentions[]{".cpp", ".cxx", ".cc"};
constexpr int ESIZE{sizeof(extentions) / sizeof(extentions[0])};

bool Utility::isThisInputFile(const std::string &file)
{
    bool flag{false};
    for (int i = 0; i < ESIZE; ++i)
    {
        auto index = file.find(extentions[i]);
        if (index != std::string::npos)
        {
            flag = true;
            break;
        };
    };
    return flag;
};
bool Utility::compileTheseFiles(const std::vector<std::string> &files)
{
    std::string c_files{};
    std::string compile_command{"g++ "};
    for(const auto&file:files)
    {
        c_files+=(" \""+file+"\"");
    };
    compile_command+=c_files;
    return system(compile_command.c_str())==0;
};