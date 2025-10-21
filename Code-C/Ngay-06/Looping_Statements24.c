/*
Viết chương trình in bảng nhân 10×10, mỗi dòng ứng với 1 số từ 1 đến 10.
Đặc biệt, định dạng bảng ngang nhưng phải xổ dọc kết quả!
*/

#include "stdio.h"
#include "stdint.h"
int z = 1;

int main(void){
    for(int i = 1; i <= 10; i++){
        printf(" BCC %d \t\t", i);
        if(i == 10) printf("\n");
    } 
    for(int i = 1; i<=10; i++){
        for(int j =1; j <= 10; j++){
            printf("% d x %d = %d \t", j, i, i*j);
        }
        printf("\n");
    }
}