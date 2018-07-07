#pragma once
#include <algorithm>
#include <limits>
#include <vector>

namespace algorithm {
struct Box {
    unsigned depth_;
    unsigned width_;
    unsigned height_;
    Box( unsigned depth, unsigned width, unsigned height ) {
        depth_  = depth;
        width_  = width;
        height_ = height;
    }
};

bool isSmaller( const Box& a, const Box& b ) {
    return ( ( a.height_ < b.height_ ) && ( a.width_ < b.width_ ) && ( a.depth_ < b.depth_ ) );
}

unsigned stack_boxes( const std::vector<Box>& boxes, const Box& bottom, size_t index,
                      std::vector<unsigned>& stacked_heights ) {
    if ( index >= boxes.size() ) return 0;
    Box newBottom        = boxes.at( index );
    int heightWithBottom = 0;
    if ( bottom.height_ == 0 || isSmaller( newBottom, bottom ) ) {
        if ( stacked_heights.at( index ) == 0 ) {
            stacked_heights.at( index ) =
                stack_boxes( boxes, newBottom, index + 1, stacked_heights );
            stacked_heights.at( index ) += newBottom.height_;
        }
        heightWithBottom = stacked_heights.at( index );
    }
    int heightWithoutBottom = stack_boxes( boxes, bottom, index + 1, stacked_heights );
    return std::max( heightWithBottom, heightWithoutBottom );
}

unsigned tallest_stack( std::vector<Box> boxes ) {
    std::sort( boxes.begin(), boxes.end(),
               []( const Box& box1, const Box& box2 ) { return box1.height_ > box2.height_; } );
    std::vector<unsigned> stacked_heights( boxes.size(), 0 );
    Box empty_box( 0, 0, 0 );
    return stack_boxes( boxes, empty_box, 0, stacked_heights );
}
} // namespace algorithm