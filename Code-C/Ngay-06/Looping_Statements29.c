/*
In hình vuông các chữ cái:
In bảng 3x3, mỗi ô là một chữ cái liên tiếp của alphabet (A B C … I).
A - Z	65 -> 90
*/

#include "stdio.h"
#include "stdint.h"
uint8_t alphabet = 64; //Bat dau bang truoc chu A
int main(void){
    uint8_t i = 1;
    while(i <= 3){
        uint8_t j =1;
        while (j <= 3)
        {
            alphabet++;
            printf(" %c ", alphabet);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}