/*
Khai báo int a = 5, b = 15; int *ptr = &a; int **pptr = &ptr;
Sau đó đổi hướng ptr trỏ sang b bằng cách sử dụng pptr.
In ra a và b để xác nhận.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 5, b = 15;
    int *ptr = &a;
    int **pptr = &ptr;

    printf("Dia chi hien tai ptr tro toi la %p \n", *pptr);
    *pptr = &b;
    printf("Dia chi hien tai ptr tro toi la %p \n", *pptr);
    return 0;
}
