/*
----------------------------------------------------------
🧮 Problem: Keep Only the Highest Set Bit
----------------------------------------------------------
You are given a 16-bit register (uint16_t).
Return a value where only the highest (leftmost) set bit
is retained. All other bits must be cleared.

----------------------------------------------------------
🧠 Example 1:
Input:  44  → Binary: 0000000000101100
Output: 32  → Binary: 0000000000100000

🧠 Example 2:
Input:  512 → Binary: 0000001000000000
Output: 512 → Binary: 0000001000000000

🧠 Example 3:
Input:  255 → Binary: 0000000011111111
Output: 128 → Binary: 0000000010000000
----------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>

uint16_t highest_set_bit(uint16_t reg) {
    uint8_t temp = 0;
    uint16_t temp_reg = reg;

    // Đếm vị trí của bit cao nhất
    while (temp_reg != 0) {
        temp++;
        temp_reg /= 2;
    }

    // Xoá tất cả bit nhỏ hơn bit cao nhất
    for (uint8_t i = 0; i < temp - 1; i++) {
        reg &= ~(1 << i);
    }
    return reg;
}

int main() {
    uint16_t reg;
    scanf("%hu", &reg);
    printf("%hu", highest_set_bit(reg));
    return 0;
}
