/*
In bảng lặp số lẻ 4x3:
In ra bảng 4 dòng, mỗi dòng 3 số lẻ liên tiếp nhau (1, 3, 5, … 23). Dùng DO-WHILE
*/
#include "stdio.h"
#include "stdint.h"
uint8_t sum = 1;

int main(void){
    uint8_t i = 1;
    do{
        uint8_t j =1;
        do{
            printf(" %d \t", sum);
            sum+=2;
            j++;
        }while(j <= 3);

        //printf("i = %d ", i);
        printf("\n");
        i++;

    }while(i <= 4);
    return 0;
}