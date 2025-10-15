/*
Viết chương trình nhập hai số nguyên a, b.
In “Equal” nếu hai số bằng nhau.
In “A greater” nếu a > b, ngược lại in “B greater”.
*/

#include "stdio.h"
#include "stdint.h"
int a, b;

int main (void){
    printf("Nhap 2 so nguyen vao \n");
    scanf("%d %d", &a, &b);
    if(a == b) printf("is equal !");
    else if (a > b) printf("A greater !");
    else printf("B greater");
    return 0;
}