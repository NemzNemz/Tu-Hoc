/*
for–while:
In ra bảng 5 dòng, mỗi dòng gồm các số chia hết cho 3 nhỏ hơn hoặc bằng 15.
*/
#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i = 1; i <= 5; i++){
        uint8_t n = 1;
        while (n <= 15)
        {
            n++;
            if(n %3 == 0) printf(" %d ", n);
        }
        n = 1;
        printf("\n");
    }
    return 0;
}