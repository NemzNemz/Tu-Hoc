/*
Viết hàm void hit(void) dùng biến static local để đếm số lần hàm được gọi.
Trong main(), gọi hit() 5 lần liên tiếp.
In ra số lần đếm mỗi lần gọi.
*/
#include "stdint.h"
#include "stdio.h"
void hit(void){
    static uint8_t c = 0;
    c++;
    printf("%d", c);
}

int main(void){
    for (uint8_t i = 1; i <= 5; i++)
    {
        hit();
    }
    return 0;
}
