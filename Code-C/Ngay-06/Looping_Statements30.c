/*
Tam giác sao ngược:
Dòng 1 có 5 sao, dòng 2 có 4, ... cho đến dòng cuối chỉ có 1.
*/

#include "stdio.h"
#include "stdint.h"
int main(void){
    uint8_t i = 1;
    while (i <= 5)
    {
        uint8_t j = 5;
        while (j >= i)
        {
            printf(" * ");
            j--;
        }
        printf("\n");
        i++;
    }
    return 0;
}