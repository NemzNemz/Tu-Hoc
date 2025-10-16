/*
Nhập số n. Nếu n < 0, nhảy đến nhãn invalid: và in “Invalid input”.
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main (void){
    start:
    printf("Vui long nhap n! \n");
    scanf("%d", &n);
    if(n < 0) {
        printf("Ko hop le !! Phai lon hon 0 \n");
        goto start;
    }
    printf("N cua ban la %d \n", n);
    return 0;
}