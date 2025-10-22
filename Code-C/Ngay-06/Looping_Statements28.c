/*
Tam giác số tăng đều:
In tam giác số, dòng thứ i có i số, bắt đầu từ 1.
1
2 3
4 5 6
7 8 9 10
*/
#include "stdio.h"
#include "stdint.h"
uint8_t sum = 0;
int main(void){
    uint8_t i = 1;
    while (i <= 4)
    {
        uint8_t j =1;
        while(j <= i)
        {
            sum++;
            printf(" %d ", sum);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}