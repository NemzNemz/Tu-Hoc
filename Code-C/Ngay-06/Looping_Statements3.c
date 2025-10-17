/*
In ra bảng cửu chương của số 7 (từ 7×1 đến 7×10).
*/

#include "stdio.h"
#include "stdint.h"
int n = 7;

int main(void){
    for(int i = 1; i <= 10; i++){
        printf("%d ", n * i);
    }
    return 0;
}