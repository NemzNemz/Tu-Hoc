/*
Viết chương trình in ra tam giác số ngược (nghĩa là dòng 1 có 5 số, dòng 2 có 4 số, …) 
với các số liên tiếp nhau bắt đầu từ 1.
*/
#include "stdio.h"
#include "stdint.h"
int n =1;

int main(void){
    for(int i =0; i <= 5; i++){
        for(int j = 5 - i; j > 0; j--){
            printf("%d \t", n);
            n++;
        }
        printf("\n");
    }
}
