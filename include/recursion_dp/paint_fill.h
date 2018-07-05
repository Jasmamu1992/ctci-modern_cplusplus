#pragma once
#include <vector>

namespace algorithm {
using image = typename std::vector<std::vector<unsigned short>>;

bool fill_paint( image& screen, int row, int col, const unsigned short ocolor,
                 const unsigned short& ncolor ) {
    if ( row < 0 || row >= screen.size() || col < 0 || col >= screen[0].size() ) return false;
    if ( screen[row][col] == ocolor ) {
        screen[row][col] = ncolor;
        fill_paint( screen, row - 1, col, ocolor, ncolor );
        fill_paint( screen, row + 1, col, ocolor, ncolor );
        fill_paint( screen, row, col - 1, ocolor, ncolor );
        fill_paint( screen, row, col + 1, ocolor, ncolor );
    }
    return true;
}
bool fill_paint( image& screen, int row, int col, const unsigned short& ncolor ) {
    if ( screen[row][col] == ncolor ) return false;
    return fill_paint( screen, row, col, screen[row][col], ncolor );
}
} // namespace algorithm