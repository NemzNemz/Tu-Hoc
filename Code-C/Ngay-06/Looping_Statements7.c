/*
Nhập vào một số nguyên n, in ra n! (giai thừa của n).
*/

#include "stdio.h"
#include "stdint.h"
int n, sum = 1;

int main(void){
    printf("Moi nhap n! \n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        sum *= i;
    }
    printf("Giai thua cua n la %d \n", sum);
    return 0;
}