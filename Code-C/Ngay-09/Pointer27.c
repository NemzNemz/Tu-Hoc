/*
Viết hàm void swap(void *a, void *b, int size);
Sử dụng memcpy hoặc cast thủ công để đổi chỗ 
giá trị của hai biến bất kỳ (int, float, double...).
*/
#include "stdio.h"
#include "stdint.h"
#include "string.h"
//API
void swap(void *ptr_a, void *ptr_b, int size);
//FUNCTION
void swap(void *ptr_a, void *ptr_b, int size){
    //Ban chat, mang la 1 con tro tro den phan tu dau tien
    char temp_r[size];
    char *tempa;
    tempa = (char*)ptr_a;

    char *tempb;
    tempb = (char*)ptr_b;
    for(uint8_t i = 0; i < size; i++)
    {
        temp_r[i] = tempa[i];
    }

    for(uint8_t i = 0; i < size; i++)
    {
        tempa[i] = tempb[i];
    }

    for(uint8_t i = 0; i < size; i++)
    {
        tempb[i] = temp_r[i];
    }
}

int main(void){
    int a = 10;
    float b = 36.36;
    swap(&a, &b, 4);
    printf("%.2f --- %d", *(float*)&a, *(int*)&b);
    return 0;
}
