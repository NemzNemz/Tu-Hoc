/*
Bài 8 – Gán kết hợp
Khởi tạo a = 10, b = 3, rồi lần lượt in ra kết quả sau mỗi phép:
a += b, a -= b, a *= b, a /= b, a %= b.
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t a = 10;
volatile uint8_t b = 3;

int main(void) {
    printf("a += b = %d \n", a += b);   //Tuong duong a = a+b
    printf("a -= b = %d \n", a -= b);   //Tuong duong a = a-b
    printf("a *= b = %d \n", a *= b);   //Tuong duong a = a*b
    printf("a /= b = %d \n", a /= b);   //Tuong duong a = a/b
    printf("a %%= b = %d \n", a %= b);  //Tuong duong a = a%b
}