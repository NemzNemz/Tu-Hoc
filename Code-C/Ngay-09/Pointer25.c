/*
Khai báo int, float, char, rồi tạo một con trỏ void* lần lượt trỏ đến từng biến.
In giá trị của biến thông qua void* sau khi ép kiểu tương ứng.
*/
#include "stdio.h"
#include "stdint.h"

int main(void){
    int x = 500;
    float y = 31.1;
    char z = 'C';

    void *ptr_x = &x;
    void *ptr_y = &y;
    void *ptr_z = &z;

    printf("Gia tri cua ptr_x la %d \n", *(int*)ptr_x);
    printf("Gia tri cua ptr_x la %.2f \n", *(float*)ptr_y);
    printf("Gia tri cua ptr_x la %c \n", *(char*)ptr_z);
    return 0;
}