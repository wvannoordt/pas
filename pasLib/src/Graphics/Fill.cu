#include "DrawingOperations.h"
#include "CuUtils.hx"
namespace pasLib
{
    int n=0;
    __global__ void K_Fill(int color, int wid, int hei, int* image)
    {
        int i = blockIdx.y*blockDim.y + threadIdx.y;
		int j = blockIdx.x*blockDim.x + threadIdx.x;
        if (i < wid && j < hei)
        {
            //*(image + i*wid+j) = color;
        }
    }
    
    void Fill(int color)
    {
        n++;
        int wid, hei;
        int* buf;
        GetWindowBufferInfo(&wid, &hei, &buf);
        int num_blocks_w = (wid  + (BLOCK_SIZE-1))/BLOCK_SIZE;
        int num_blocks_h = (hei + (BLOCK_SIZE-1))/BLOCK_SIZE;
        dim3 gridConf(num_blocks_w, num_blocks_h);
        dim3 blockConf(BLOCK_SIZE, BLOCK_SIZE);
        if (n==50)
        {
            __sdump(wid);
            __sdump(hei);
            __sdump(color);
            __sdump(buf);
            __sdump(num_blocks_w);
            __sdump(num_blocks_h);
            __sdump(BLOCK_SIZE);
            K_Fill<<<gridConf, blockConf>>>(color, wid, hei, buf);
            CU_CHK(cudaGetLastError());
        }
            
    }
}