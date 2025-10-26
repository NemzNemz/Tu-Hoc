/*
----------------------------------------------------------
🧮 Problem: Check if K-th Bit is Set
----------------------------------------------------------
Write a C program to check if the K-th bit (0-based index)
of an integer N is set (1) or not (0).

Input Format:
- Two integers N and K.

Output Format:
- Print 1 if the K-th bit of integer N is set (1), otherwise 0.

----------------------------------------------------------
🧠 Example:
Input:  N = 8,  K = 3
Binary value of 8: 00001000
→ The 3rd bit is set → Output = 1
----------------------------------------------------------
*/

#include <stdio.h>

int isKthBitSet(int n, int k) {
    if (n & (1 << k))
        return 1;
    else
        return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", isKthBitSet(n, k));
    return 0;
}
