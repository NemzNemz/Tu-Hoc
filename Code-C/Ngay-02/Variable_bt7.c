/*
Bài 7 – Hằng số với const
Khai báo const double PI = 3.14159;.
Tính diện tích hình tròn với bán kính r = 5 và in ra kết quả.
Thử thay đổi giá trị PI = 3.14; để xem compiler báo lỗi gì.
*/

#include "stdio.h"
#include "stdint.h"
const double PI = 3.14159;
const uint8_t r = 5;
float answ;
//S = PI x R^2

int main(void){ 
    answ = PI * r*2;
    printf("Dien tich hinh tron la %.5f", answ);
    //double *ptr_PI = (double*)&PI; //co tinh tro vao de thay doi PI
    //*ptr_PI = 3.14;
    return 0;
}