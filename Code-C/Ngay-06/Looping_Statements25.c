/*
Tạo một bảng 4×4 chứa số thứ tự tăng dần từ 1 → 16, in theo dạng ma trận.
*/
#include "stdio.h"
#include "stdint.h"
int n = 1;

int main(void){
    for(int i =1; i <= 4; i++){
        for(int j = 1; j<=4; j++){
            printf("%d ", n);
            n++;
        }
        printf("\n");
    }
}