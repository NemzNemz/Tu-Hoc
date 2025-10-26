/*
----------------------------------------------------------
🧮 Problem: Clear the Bit in an 8-bit Register
----------------------------------------------------------
You are working with an 8-bit control register.
Write a function to clear (set to 0) the bit at a given position
without affecting other bits.

Use 0-based indexing (0 = LSB, 7 = MSB).

----------------------------------------------------------
🧠 Example 1:
Input:  reg = 0b00000111, pos = 0
Output: 0b00000110

🧠 Example 2:
Input:  reg = 0b00000111, pos = 3
Output: 0b00000111
----------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>

uint8_t clear_bit(uint8_t reg, uint8_t pos) {
    reg &= ~(1 << pos);
    return reg;
}

int main() {
    uint8_t reg, pos;
    scanf("%hhu %hhu", &reg, &pos);
    uint8_t result = clear_bit(reg, pos);
    printf("%u", result);
    return 0;
}
