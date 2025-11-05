/*
Viết hàm void swap(int *a, int *b) để hoán đổi giá trị của hai biến.
Gọi hàm trong main() và in kết quả sau khi swap.
*/

#include "stdio.h"
#include "stdint.h"
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int a = 10, b = 20;
    swap(&a, &b);
    printf("A = %d, B = %d", a, b);
    return 0;
}