#ifndef DEBUG_TOOLS_H
#define DEBUG_TOOLS_H
#include <iostream>

#define __longline "---------------------------------------------------------"

#define __dump(mystuff) {std::cout << __FILE__ <<  " (" << __LINE__ << "): " << mystuff << std::endl;}
#define __qdump(mystuff) {std::cout << mystuff << std::endl;}
#define __sdump(mystuff) {std::cout << #mystuff << ": " <<  mystuff << std::endl;}
#define __dumpwait(mystuff) {std::cout << __FILE__ <<  " (" << __LINE__ << "): " << mystuff << std::endl;std::cin.get();}
#define __erkill(mystuff) {std::cout << __longline <<std::endl << "Terminate called from " << __FILE__ <<  ", line (" << __LINE__ << "): " << mystuff << std::endl << __longline << std::endl; abort();}

#endif
