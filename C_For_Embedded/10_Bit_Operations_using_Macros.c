/* 
------------------------------------------------------------
🧩 Problem: Bit Operations using Macros
------------------------------------------------------------
In embedded systems, modifying specific bits of control or 
status registers is a frequent task. You’re given an 8-bit 
register (uint8_t) and must perform the following operations:

Requirements:
- Set bits 2 and 7
- Clear bit 3
- Toggle bit 5
- Apply operations in the given order
- Return the updated register value

Use proper bitwise macros for code maintainability.

------------------------------------------------------------
💡 Example 1:
Input:  0
Output: 164

Binary transformation:
00000000 → (set bit2, bit7) → 10100100 → Decimal 164
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>

// Define macros
#define SET_BIT(REG, POS)    ((REG) |= (1U << (POS)))
#define CLEAR_BIT(REG, POS)  ((REG) &= ~(1U << (POS)))
#define TOGGLE_BIT(REG, POS) ((REG) ^= (1U << (POS)))

// Function to modify register
uint8_t modify_register(uint8_t reg) {
    SET_BIT(reg, 2);   // Set bit 2
    SET_BIT(reg, 7);   // Set bit 7
    CLEAR_BIT(reg, 3); // Clear bit 3
    TOGGLE_BIT(reg, 5);// Toggle bit 5
    return reg;
}

// Main function
int main() {
    uint8_t reg;
    scanf("%hhu", &reg);
    uint8_t result = modify_register(reg);
    printf("%u", result);
    return 0;
}
