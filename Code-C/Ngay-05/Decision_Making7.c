/*
Nhập ba số nguyên a, b, c.
In ra số lớn nhất.
*/

#include "stdio.h"
#include "stdint.h"
int a, b, c;

int main (void){
    printf("Nhap 3 so nguyen vao \n");
    scanf("%d %d %d", &a, &b, &c);
    if((a > b) && (a > c)) printf("a lon nhat");
    else if ((b > a) && (b > c)) printf("b lon nhat");
    else if((a == b) && (b == c)) printf("3 so bang nhau");
    else printf("c lon nhat");
    return 0;
}