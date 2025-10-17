/*
Trung cấp (tư duy chỉ số & điều kiện)
In bảng cửu chương 1–10, mỗi hàng là bảng nhân của một số (1×1..1×10 trên dòng 1, 2×1..2×10 dòng 2, ...), 
căn chỉnh thành cột (đảm bảo khoảng cách).
*/
#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i =1; i <= 10; i++){
        printf("Bang nhan %d.  ", i);
        for(int j =1; j <= 10; j++){
            //printf("Bang nhan %d.    ", i);
            printf(" %d x %d = %d ", i, j, i*j);
        }   
        printf("\n");
    }
    return 0;
}