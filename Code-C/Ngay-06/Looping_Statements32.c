/*
Tam giác số giảm dần: DO-WHILE
In tam giác số, dòng 1 có 4 số, dòng 2 có 3, ... dòng cuối có 1 số, số bắt đầu từ 10 giảm dần.
10 9 8 7
6 5 4
3 2
1
*/

#include "stdio.h"
#include "stdint.h"
uint8_t sum = 10;

int main(void){
    uint8_t i = 1;
    do{
        uint8_t j = 4;
        do{
            printf(" %d \t", sum);
            sum--;
            j--;
        }while(j >= i);
        printf("\n");
        i++;
    }while(i <= 4);
    return 0;
}