#include "include/bit_manipulation/draw_line.h"
#include <gtest/gtest.h>

using byte = algorithm::byte;

TEST( DRAW_LINE, X1_X2_INSAMEBYTE ) {
    byte screen[] = {0x00, 0x00};
    algorithm::draw_line( screen, 8, 2, 5, 0 );
    byte output[] = {0x3c, 0x00};

    ASSERT_EQ( output[0], screen[0] );
}

TEST( DRAW_LINE, X1_X2_NOTINSAMEBYTE_ROW0 ) {
    byte screen[] = {0x00, 0x00, 0x00, 0x00};
    algorithm::draw_line( screen, 16, 7, 8, 0 );
    byte output[] = {0x01, 0x80, 0x00, 0x00};

    ASSERT_EQ( output[0], screen[0] );
    ASSERT_EQ( output[1], screen[1] );
}

TEST( DRAW_LINE, X1_X2_NOTINSAMEBYTE_ROW1 ) {
    byte screen[] = {0x00, 0x00, 0x00, 0x00};
    algorithm::draw_line( screen, 16, 23, 25, 0 );
    byte output[] = {0x00, 0x00, 0x01, 0xC0};

    ASSERT_EQ( output[0], screen[0] );
    ASSERT_EQ( output[1], screen[1] );
    ASSERT_EQ( output[2], screen[2] );
    ASSERT_EQ( output[3], screen[3] );
}