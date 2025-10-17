/*
Tính tổng của các số từ 1 đến 100 bằng for loop.
*/

#include "stdio.h"
#include "stdint.h"
int n = 0;

int main(void){
    for(int i = 1; i <= 100; i++){
        n+=i;
        printf("%d ", n);
    }
    return 0;
}