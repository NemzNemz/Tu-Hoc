/*
Bài 1.
Khai báo hai biến x và y, cho x = 10, y = 20.
Dùng con trỏ duy nhất để lần lượt:
Gán x = 15,
Sau đó gán y = 25,
rồi in ra kết quả
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int x = 10, y = 20;
    int *ptr = &x;
    *ptr = 15;

    ptr = &y;
    *ptr = 25;

    printf("X = %d, Y = %d", x, y);
    return 0;
}