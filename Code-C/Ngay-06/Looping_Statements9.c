/*
In ra tất cả các số chia hết cho 3 hoặc 5 trong khoảng từ 1 đến 100, nhưng không được in ra các số chia hết cho cả 3 và 5.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i = 1; i <= 100; i++){
        if((i % 3 != 0) && (i % 5 != 0)){
            printf("%d \n", i);
        }
    }
    return 0;
}