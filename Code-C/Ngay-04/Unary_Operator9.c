/*
Bài 9 – Toán tử điều kiện (?:)
Nhập hai số và in ra số lớn hơn bằng toán tử ba ngôi.
*/

#include "stdio.h"
#include "stdint.h"
volatile uint8_t a = 0;
volatile uint8_t b = 0;

int main(void) {
    printf("Nhap vao so a \n");
    scanf("%d", &a);
    printf("Nhap vao so n \n");
    scanf("%d", &b);
    //Toan tu 3 ngoi
    (a > b) ? printf("a > b") : printf("a < b");
}