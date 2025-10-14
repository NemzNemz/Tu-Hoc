/*
Bài 1 – Tổng và Hiệu
Nhập hai số nguyên, in ra tổng, hiệu, tích, thương và phần dư của chúng.
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t x = 0;
volatile uint8_t y =0;

uint8_t tong_2(uint8_t x, uint8_t y){
    return x+y;
}

uint8_t hieu_2(uint8_t x, uint8_t y){
    return x-y;
}

uint32_t tich_2(uint8_t x, uint8_t y){
    return x*y;
}

uint8_t thuong_2(uint8_t x, uint8_t y){
    return x/y;
}

uint8_t thuong_2_co_du(uint8_t x, uint8_t y){
    return x%y;
}


int main(void) {
    printf("Nhap 2 so x va y \n");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    printf("Tong 2 so la %d \n", tong_2(x, y));
    printf("Hieu 2 so la %d \n", hieu_2(x, y));
    printf("Tich 2 so la %d \n", tich_2(x, y));
    printf("Thuong 2 so la %d \n", thuong_2(x, y));
    printf("So du khi chia 2 so la %d \n", thuong_2_co_du(x, y));
    return 0;
}