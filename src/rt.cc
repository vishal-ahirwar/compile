#include<rt.h>
#include<cstdio>
#include<fmt/core.h>
#include<fmt/color.h>
RT::RT(const std::string&msg):_msg{msg}
{
    _start=std::chrono::high_resolution_clock::now();
};
RT::~RT()
{
    _end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>elaped_time{_end-_start};
    fmt::print(fmt::emphasis::faint,"Time taken by {} {:.2f}s\n",_msg.c_str(),elaped_time.count());
};