#include "GlobalArgs.h"
namespace pasLib
{
    char** globArgv;
    int globArgc;
    bool globInitialized = false;
    void AddArg(std::string arg)
    {
        globArgv[globArgc] = (char*)arg.c_str();
        globArgc++;
    }
}