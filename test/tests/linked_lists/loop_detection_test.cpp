#include "include/linked_lists/loop_detection.h"
#include <gtest/gtest.h>

using algorithm::Forward_List_Node;
using algorithm::loopBeginning;

TEST( LOOP_DETECTION, HALF_LOOP_LIST ) {
    std::array<int, 8> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto end   = first;
    for ( auto& num : input ) {
        end->next_ = std::make_shared<Forward_List_Node<int>>( num );
        end        = end->next_;
    }

    auto loop_point             = first;
    unsigned int loop_point_pos = input.size() / 2;
    while ( loop_point_pos > 0 ) {
        loop_point = loop_point->next_;
        loop_point_pos--;
    }
    end->next_ = loop_point;

    auto result = loopBeginning( first );
    ASSERT_EQ( loop_point, result );
}

TEST( LOOP_DETECTION, FULL_LOOP_LIST ) {
    std::array<int, 8> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto end   = first;
    for ( auto& num : input ) {
        end->next_ = std::make_shared<Forward_List_Node<int>>( num );
        end        = end->next_;
    }

    auto loop_point = first;
    end->next_      = first;

    auto result = loopBeginning( first );
    ASSERT_EQ( loop_point, result );
}

TEST( LOOP_DETECTION, NO_LOOP_LIST ) {
    std::array<int, 8> input{8, 7, 6, 5, 4, 3, 2, 1};
    auto first = std::make_shared<Forward_List_Node<int>>( 0 );
    auto end   = first;
    for ( auto& num : input ) {
        end->next_ = std::make_shared<Forward_List_Node<int>>( num );
        end        = end->next_;
    }

    end->next_ = nullptr;

    auto result = loopBeginning( first );
    ASSERT_EQ( nullptr, result );
}