/*
Cơ bản (nắm chắc thứ tự)
In một tam giác vuông phải bằng * (n hàng):
*
**
***
với n=5.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i =0; i < 5; i++){
        for(int j =0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}