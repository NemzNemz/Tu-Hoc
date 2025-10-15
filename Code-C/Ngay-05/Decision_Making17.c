/*
Nhập số nguyên n, in “Even” hoặc “Odd” bằng ?:.
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main (void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    n % 2 == 0 ? printf("So nay la so chan") : printf("So nay la so le");
    return 0;
}