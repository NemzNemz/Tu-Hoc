/*
Bài 10 – Bit mask
Nhập một số nguyên và một vị trí bit pos (0-based).
Dùng bitwise AND và bit shift để kiểm tra xem bit đó là 0 hay 1.
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t bit = 0;
volatile uint8_t pos = 0;

int main(void) {
    printf("Nhap vao so bit \n");
    scanf("%d", &bit);
    printf("Nhap vao vi tri bit \n");
    scanf("%d", &pos);
    printf("%d \n", bit & (1 << pos));
    //AND + SHIFT N BIT
    if(bit & (1 << pos)) printf("bit nay la 1");
    else printf("bit nay la 0");
}