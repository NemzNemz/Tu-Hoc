/*
Viết đoạn code in “Even” nếu n chia hết cho 2.
*/

#include "stdio.h"
#include "stdint.h"
uint8_t n;

int main (void){
    printf("Nhap n! \n");
    scanf("%d", &n);
    //n AND 0001. Bit LSB = 1 -> Le, 0 thi chan
    if((n & 1) == 0) printf("Even!");
    return 0;
}