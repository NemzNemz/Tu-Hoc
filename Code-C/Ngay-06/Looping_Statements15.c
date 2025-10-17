/*
Cơ bản (nắm chắc thứ tự)
In ma trận 3×5 chứa chỉ số (i,j) theo format i,j (mỗi dòng một hàng).
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i =0; i < 3; i++){
        for(int j =0; j < 4; j++){
            printf("i.%d ", i);
            printf("j %d ", j);
        }
        printf("\n");
    }
    return 0;
}