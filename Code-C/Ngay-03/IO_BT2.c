/*
Bài 2: Tổng hai số nguyên
Nhập vào 2 số nguyên từ bàn phím.
In ra tổng của chúng dưới dạng:
Sum of 10 and 20 is 30
*/

#include <stdio.h>
#include <stdint.h>
int a, b;

int main() {
    printf("Moi nhap 2 so nguyen ! \n");
    printf("So thu nhat \n");
    scanf("%d", &a);
    printf("So thu hai \n");
    scanf("%d", &b);
    printf("Sum of %d and %d is %d \n", a, b, a+b);
    return 0;
}