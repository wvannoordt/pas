#ifndef GLOBAL_ARG_H
#define GLOBAL_ARG_H

#define GLOB_ARG_MAX 32

#include <string>

namespace pasLib
{
    extern char** globArgv;
    extern int globArgc;
    extern bool globInitialized;
    void AddArg(std::string arg);
}

#endif