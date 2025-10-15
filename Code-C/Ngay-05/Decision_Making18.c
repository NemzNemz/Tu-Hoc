/*
Nhập a, b, dùng ?: để in ra số lớn hơn.
*/
#include "stdio.h"
#include "stdint.h"
int a, b;

int main (void){
    printf("Nhap 2 so nguyen vao \n");
    scanf("%d %d", &a, &b);
    a > b ? printf("A lon hon B, A = %d", a) : printf("B lon hon A, B = %d", b);
    return 0;
}