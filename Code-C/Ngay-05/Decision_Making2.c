/*
Viết chương trình:
Nhập một số nguyên x
Nếu x ≥ 0 → in “Positive or Zero”
Ngược lại → in “Negative”
Hãy dùng cú pháp chuẩn, không bỏ {} dù chỉ có 1 lệnh.
*/
#include "stdio.h"
#include "stdint.h"
int x;

int main (void){
    printf("Nhap n! \n");
    scanf("%d", &x);
    //Neu x ko be hon 0
    if(!(x < 0)) {
        printf("Positive or Zero !");
    }
    else {
        printf("Negative !");
    }
}