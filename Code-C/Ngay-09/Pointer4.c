/*
Bài 4.
Tạo biến a = 10, b = 20.
Tạo con trỏ p1 trỏ tới a và p2 trỏ tới b.
In ra giá trị của a - b bằng cách chỉ sử dụng con trỏ, không dùng tên biến trực tiếp.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 10, b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;
    printf("Gia tri cua a - b = %d", (*ptr_a) - (*ptr_b));
    return 0;
}