/*
Nhập vào n, in ra tổng bình phương của các số từ 1 đến n.
*/

#include "stdio.h"
#include "stdint.h"
int n, anw = 0;

int main(void){
    printf("Moi nhap n !\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        anw += i*i;
    }
    printf("Tong binh phuong la %d", anw);
    return 0;
}