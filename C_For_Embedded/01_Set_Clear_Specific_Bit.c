/*
===============================================
EWskills – Embedded C Programming
Topic: Bitwise Operations
Task 1: Set or Clear a Specific Bit in a Register

Write a C program to set or clear a specific bit
in an 8-bit register based on user input.

Input:
  - An 8-bit integer (0–255)
  - Bit position (0–7)
  - Mode (0 = clear, 1 = set)

Output:
  - Modified register value after the operation

Example:
  Input : 7 1 0
  Output: 5
===============================================
*/
#include <stdio.h>

unsigned char modifyBit(unsigned char reg, int pos, int mode) {
    if (mode == 0)
        return reg & ~(1 << pos);   // clear
    else if (mode == 1)
        return reg | (1 << pos);    // set
    return reg;
}

int main() {
    unsigned char reg;
    int pos, mode;
    scanf("%hhu %d %d", &reg, &pos, &mode);
    printf("%d", modifyBit(reg, pos, mode));
    return 0;
}
