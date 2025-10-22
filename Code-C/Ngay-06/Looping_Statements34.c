/*
Tam giác sao tăng:
Dòng 1 có 1 sao, dòng 2 có 2 sao, dòng 3 có 3 sao, dòng 4 có 4 sao.
(Lưu ý: dùng do-while, không while/for.)
*/
#include "stdio.h"
#include "stdint.h"

int main(void){
    uint8_t i = 1;
    do{
        uint8_t j = 1;
        do{
            printf(" * ");
            j++;
        }while (j <= i);
        printf("\n");
        i++;
    }while(i <= 5);
    return 0;
}