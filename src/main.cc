
// Auto Genrated C++ file by aura CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <cstdio>
#include <compileconfig.h>
#include <filesystem>
#include <utility.h>
#include <rt.h>

namespace fs = std::filesystem;
int main(int argc, char *argv[])
{
    RT rt("compile");
    std::vector<std::string> files{};
    std::string path{};
    auto dir = fs::current_path();
    for (const auto &name : fs::directory_iterator(dir))
    {
        path = name.path().string();
        if (name.is_directory())
            continue;
        if (Utility::isThisInputFile(path))
            files.push_back(path);
    };
    fprintf(stderr, "Compiling...\n");
    if (Utility::compileTheseFiles(files))
    {
        fprintf(stderr, "Compilation Completed.\n");
    }
    else
    {
        fprintf(stderr, "Compilation Failed!\n");
    };
    return 0;
};
