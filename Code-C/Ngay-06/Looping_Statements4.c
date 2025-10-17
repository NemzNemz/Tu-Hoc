/*
Nhập vào một số nguyên n. In ra tất cả các số chẵn từ 0 đến n.
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main(void){
    printf("Moi nhap n !\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) printf("%d ",i);
    }
    return 0;
}