/*
Viết hàm int square(int x) trả về bình phương của x, rồi gọi nó trong main.
*/

#include "stdio.h"
#include "stdint.h"
int n;

int square(int x){
    return x*x;
}

int main (void){
    printf("Moi nhap n vao !\n");
    scanf("%d", &n);
    printf("Binh phuong cua n la %d", square(n));
    return 0;
}