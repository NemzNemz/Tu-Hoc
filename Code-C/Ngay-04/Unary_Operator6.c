/*
Bài 6 – So sánh hai số
Nhập hai số và in ra kết quả của tất cả các phép so sánh (<, >, <=, >=, ==, !=).
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t a = 0;
volatile uint8_t n = 0;

int main(void) {
    printf("Nhap vao so a \n");
    scanf("%d", &a);
    printf("Nhap vao so n \n");
    scanf("%d", &n);
    printf("Kq cua phep %d > %d  la %d \n", a, n, a > n);
    printf("Kq cua phep %d < %d  la %d \n", a, n, a < n);
    printf("Kq cua phep %d >= %d  la %d \n", a, n, a >= n);
    printf("Kq cua phep %d <= %d  la %d \n", a, n, a <= n);
    printf("Kq cua phep %d == %d  la %d \n", a, n, a == n);
    printf("Kq cua phep %d != %d  la %d \n", a, n, a != n);
}