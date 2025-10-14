/*
Bài 5 – Dịch trái và dịch phải
Nhập một số và số bước dịch, in ra a << n và a >> n.
*/

#include "stdio.h"
#include "stdint.h"
volatile uint8_t a = 0;
volatile uint8_t n = 0;

int main(void) {
    printf("Nhap so vao! \n");
    scanf("%d", &a);
    printf("Nhap so lan dich bit! \n");
    scanf("%d", &n);
    printf("Kq cua %d dich %d la %d \n", a, n, a << n);
    printf("Kq cua %d dich %d la %d \n", a, n, a >> n);
    /*
    0000 0101 << 2
    0001 0100 => 20
    0000 0101 >> 2
    0001 0001 => 1  
    */
    return 0;
}