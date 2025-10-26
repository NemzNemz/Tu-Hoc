/*
----------------------------------------------------------
🧮 Problem: Bit Toggle
----------------------------------------------------------
Write a C program to toggle the 5th bit (0-based index) of a given integer.

Requirements:
- The program should take an integer N as input.
- It should toggle the 5th bit of N:
      If that bit is 0 → make it 1.
      If that bit is 1 → make it 0.

Note:
- The 5th bit is at position 5 (using 0-based indexing).
  Example: In binary 100100, the 5th bit is 1.

----------------------------------------------------------
🧠 Example 1:
Input: 10
Binary: 00001010
Toggle 5th bit → 00101010 → Decimal: 42

🧠 Example 2:
Input: 31
Binary: 00011111
Toggle 5th bit → 01011111 → Decimal: 95
----------------------------------------------------------
*/

#include <stdio.h>

// Function to toggle the 5th bit of a given number
int toggleFifthBit(int n) {
    // XOR với (1 << 5): nếu bit 5 là 0 -> thành 1, nếu là 1 -> thành 0
    return n ^ (1 << 5);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", toggleFifthBit(n));
    return 0;
}
