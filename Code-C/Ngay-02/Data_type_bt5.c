/*
Bài 5 – Kết hợp kiểu dữ liệu
Khai báo int x = 10; double y = 3.5;
Tính x + y, x / y, y / x.
In kết quả và kiểu dữ liệu thực tế được dùng trong mỗi phép toán.
*/

#include "stdio.h"
int x = 10; 
double y = 3.5;

int main(void){
    double answ1 = x + y;
    double answ2 = x / y;
    double answ3 = y / x;
    printf("Kq answ1 la %.1lf \n", answ1);
    printf("Kq answ2 la %.1lf \n", answ2);
    printf("Kq answ3 la %.1lf \n", answ3);
    return 0;
}