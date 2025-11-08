/*
Nhập một số nguyên dương, tìm chữ số lớn nhất của số đó.
*/
#include "stdio.h"
#include "stdint.h"
//API
void nhap(unsigned int *ptr_v);
unsigned int find_max(unsigned int val);
//FUNC
void nhap(unsigned int *ptr_v){
    do
    {
        printf("Moi nhap gia tri vao!\n");
        scanf(" %d", ptr_v);
    } while (*ptr_v <= 0);
    printf("Gia tri vua nhap la %d\n", *ptr_v);
}

unsigned int find_max(unsigned int val){
    unsigned int max_digit = 0;
    unsigned int temp = val;
    while(val != 0){
        temp = val %10;
        val /= 10;
        if(max_digit < temp){
            max_digit = temp;
        }
    }
    return max_digit;
}

int main(void){
    unsigned int var;
    nhap(&var);
    printf("So lon nhat la %d", find_max(var));
    return 0;
}