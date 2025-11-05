/*
Viết đoạn code để in ra tất cả các thông tin sau của một biến int n = 123;
Giá trị (n)
Địa chỉ của n
Giá trị của con trỏ trỏ tới n
Địa chỉ của con trỏ
Giá trị truy cập qua con trỏ (*ptr)
*/
#include "stdio.h"
#include "stdint.h"

int main(void){
    int n = 10;
    int *ptr = &n;

    printf("Gia tri cua n la %d \n", n);
    printf("Dia chi cua n la %p \n", &n);
    printf("Gia tri cua con tro tro toi n la %p \n", ptr);
    printf("Dia chi cua con tro tro toi n la %p \n", &ptr);
    printf("Gia tri tai vung nho cua bien duoc tro toi la la %d \n", *ptr);
    return 0;
}
