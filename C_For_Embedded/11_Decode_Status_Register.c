/* 
------------------------------------------------------------
🧩 Problem: Decode Status Register into Human-Readable Flags
------------------------------------------------------------
Given an 8-bit status register, each bit represents a flag.
Print ONLY the names of the flags that are set (bit = 1),
one per line, in LSB→MSB order (0 → 7).

Bit mapping:
0: Power On
1: Error
2: Tx Ready
3: Rx Ready
4: Overheat
5: Undervoltage
6: Timeout
7: Reserved
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>

#define IS_BIT_SET(REG, POS) ( ((REG) >> (POS)) & 1U )

static const char* FLAG_NAME[8] = {
    "Power On", "Error", "Tx Ready", "Rx Ready",
    "Overheat", "Undervoltage", "Timeout", "Reserved"
};

int main(void) {
    uint8_t status_reg;
    if (scanf("%hhu", &status_reg) != 1) return 0;

    for (uint8_t i = 0; i < 8; ++i) {
        if (IS_BIT_SET(status_reg, i)) {
            printf("%s\n", FLAG_NAME[i]);
        }
    }
    return 0;
}

