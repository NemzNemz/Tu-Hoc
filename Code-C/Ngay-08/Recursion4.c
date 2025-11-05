/*
Đếm số chữ số của một số
Input: n = 12345 → Output: 5
*/

#include "stdio.h"
#include "stdint.h"
int count_n(int n){
    printf("Dang xu ly %d\n", n);
    if(n < 10) return 1;
    else return 1 + count_n(n/10);
}

int main(void){
    printf("%d", count_n(12345678));
    return 0;
}