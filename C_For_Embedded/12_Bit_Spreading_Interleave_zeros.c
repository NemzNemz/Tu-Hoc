/* 
------------------------------------------------------------
🧩 Problem: Bit Spreading (Interleave Bits with Zeros)
------------------------------------------------------------
Given an 8-bit value, produce a 16-bit result where each
original bit occupies the EVEN positions (0,2,4,...) and all
ODD positions are 0.

Example (bits shown MSB..LSB):
b7 b6 b5 b4 b3 b2 b1 b0  →  0 b7 0 b6 0 b5 0 b4 0 b3 0 b2 0 b1 0 b0
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t val;
    if (scanf("%hhu", &val) != 1) return 0;

    uint16_t res = 0;
    for (uint8_t i = 0; i < 8; ++i) {
        uint16_t bit = (val >> i) & 1U;
        res |= (bit << (i * 2));  // đặt vào vị trí chẵn
    }

    printf("%u", res);
    return 0;
}
