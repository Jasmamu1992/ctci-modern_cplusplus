#pragma once
#include<iostream>

namespace algorithm{
    using byte = unsigned char;
    void draw_line(byte screen[], int width, int x1, int x2, int y ){
        int start_offset = x1%8;
        int first_fullbyte = x1/8;
        if(start_offset != 0) first_fullbyte++;
        int end_offset = x2%8;
        int last_fullbyte = x2/8;
        if(end_offset!=7) last_fullbyte--;

        for(int x = first_fullbyte; x<last_fullbyte; ++x){
            screen[y *(width/8)+x] = 0xFF;
        }
    
        byte first_mask = (byte) 0xFF >> start_offset;
        byte last_mask = (byte) ~(0xFF >> (end_offset+1));
       
        //x1 and x2 in the same byte
        if(x1/8 == x2/8){
            byte mask = (byte) (first_mask & last_mask);
            screen[y *(width/8)+x1/8] |= mask;
        }
        else{
            if(start_offset != 0){
                screen[y*(width/8)+first_fullbyte-1] |= first_mask;
            }
            if(end_offset!=7){
                screen[y*(width/8)+last_fullbyte+1] |= last_mask;
            }
        }
    }
}