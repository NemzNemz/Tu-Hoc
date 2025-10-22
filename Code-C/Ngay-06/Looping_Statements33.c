/*
Bảng chữ cái ngược:
In bảng 2x5, mỗi ô là ký tự in hoa từ 'J' về 'A' (J I H G F ... A).
A - J	65 -> 74
*/
#include "stdio.h"
#include "stdint.h"
uint8_t alphabet = 74;

int main(void){
    uint8_t i = 1;
    do{
        uint8_t j = 1;
        do
        {
            printf(" %c ", alphabet);
            alphabet --;
            j++;
        } while (j <= 5);
        printf("\n");
        i++;
    }while(i <= 2);
    return 0;
}
