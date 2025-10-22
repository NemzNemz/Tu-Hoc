/*
In bảng số chẵn 4×4:
In ra bảng 4 dòng 4 cột, số chẵn liên tiếp nhau bắt đầu từ 2 (2 4 6 8 ... 32). sử dụng while
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    uint8_t i = 0;
    while(i < 4){
        uint8_t j = 1;
        while(j <= 4){
            //Cach nay ko thong minh!
            static int sum = 1;
            printf(" %d ", sum*2);
            sum++;
            j++;
        }
        i++;
        printf("\n");
    }
    return 0;
}