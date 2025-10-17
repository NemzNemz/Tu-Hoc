/*
In ra các ký tự in hoa trong bảng chữ cái tiếng Anh (A đến Z) bằng for loop.
A - Z	65 -> 90
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i = 65; i <= 90; i++){
        printf("%c \n", i);
    }
    return 0;
}