/*
Cho biến a = 5.
Khai báo con trỏ p trỏ tới a, sau đó in ra:
Giá trị của a,
Địa chỉ của a,
Giá trị của p,
Địa chỉ của p,
Giá trị của *p.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 5;
    int *ptr_a = &a;
    printf("Gia tri cua a la %d \n", a);
    printf("Dia chi cua a la %p \n", &a);
    printf("Gia tri cua p la %p \n", ptr_a);
    printf("Dia chi cua p la %p \n", &ptr_a);
    printf("Gia tri cua *p la %d \n", *ptr_a);
    return 0;
}