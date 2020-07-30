#ifndef CU_UTILS_H
#define CU_UTILS_H
#include "DebugTools.hx"
#define CU_CHK(my_kernel_call) H_INTERNAL_register_cuda_error(my_kernel_call, __FILE__, __LINE__)
static void H_INTERNAL_register_cuda_error(cudaError er, const char* file, const int line)
{
    if (er != cudaSuccess)
    {
        __erkill(cudaGetErrorString(er));
    }
}

#endif