/*
Nhập một năm bất kỳ.
Một năm là nhuận nếu:
chia hết cho 4 và không chia hết cho 100,
hoặc chia hết cho 400.
*/

#include "stdio.h"
#include "stdint.h"
int year;

int main (void){
    printf("Nhap nam vao \n");
    scanf("%d", &year);
    if((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0) printf("Day la nam nhuan");
    else printf("Ko phai!");
    return 0;
}