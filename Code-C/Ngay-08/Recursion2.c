/*
Tính tổng 1 + 2 + … + n
Gợi ý:
Tổng đến n = n + tổng đến n-1. Base case: tổng đến 0 là 0.
*/

#include "stdio.h"
#include "stdint.h"
int sum_n(uint16_t n){
    if(n == 0) return 0;
    else return n += sum_n(n - 1);
}

int main(void){
    printf("%d", sum_n(3));
    return 0;
}