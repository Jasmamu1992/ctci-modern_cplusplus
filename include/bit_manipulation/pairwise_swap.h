#pragma once

namespace algorithm{
    int pairwise_swap(int input){
        return (input & 0xaaaaaaaa) >> 1 | (input & 0x55555555) << 1;
    }
}