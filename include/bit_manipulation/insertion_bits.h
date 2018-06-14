#pragma once
#include <cstdint>

namespace algorithm {
uint32_t insert_bits_mask( uint32_t input, uint32_t bits, uint8_t to, uint8_t from ) {
    uint8_t nbits = from - to + 1;
    uint32_t mask = ( ( 1 << nbits ) - 1 ) << to;
    mask          = ~mask;
    input         = input & mask;
    return input | ( bits << to );
}
} // namespace algorithm