/*
Bài 4 – Đảo bit
In ra kết quả ~a của số nguyên a, và giải thích vì sao ra kết quả đó.
(Ôn ~ và two’s complement)
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t x = 0;

int main(void) {
    printf("Nhap so vao! \n");
    scanf("%d", &x);
    printf("So sau khi bi dao do la %d \n", ~x);
    // Nhap 9: 0000 1001 => 1111 0110 => 0000 1010 => (-)10 
}
