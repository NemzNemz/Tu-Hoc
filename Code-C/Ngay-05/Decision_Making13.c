/*
Bài 3 – Phân loại số nguyên n:
Nếu n > 0 → “Positive”
Nếu n == 0 → “Zero”
Nếu n < 0 → “Negative”
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main (void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    if(n == 0) printf("So dac biet ko am ko duong !");
    else if (n > 0) printf("So duong");
    else printf("So am!");
    return 0;
}