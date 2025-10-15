/*
Nhập a, b, c, dùng 2 cấp lồng ?: để tìm số lớn nhất
*/

#include "stdio.h"
#include "stdint.h"
int a, b, c;

int main (void){
    printf("Nhap 3 so nguyen vao \n");
    scanf("%d %d %d", &a, &b, &c);
    //Cuc ki kho hieu! Logic thuc te la
    /*
    if((a > b) && (a > c)) printf("a lon nhat");
    else if ((b > a) && (b > c)) printf("b lon nhat");
    else if((a == b) && (b == c)) printf("3 so bang nhau");
    else printf("c lon nhat");
    */
    int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("Max la %d", max);
    return 0;
}