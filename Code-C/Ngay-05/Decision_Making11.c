/*
Bài 1 – Phân loại nhiệt độ:
Nhập temp (°C).
>= 40 → “Very Hot”
>= 30 → “Hot”
>= 20 → “Warm”
>= 10 → “Cool”
< 10 → “Cold”
*/

#include "stdio.h"
#include "stdint.h"
int temp;

int main (void){
    printf("Nhap temp vao! \n");
    scanf("%d", &temp);
    if(temp >= 40) printf("Nong vcl !");
    else if(temp >= 30) printf("Kha la nong !");
    else if(temp >= 20) printf("Hoi am nhe !");
    else if(temp >= 10) printf ("Hoi lanh roi !");
    else printf("Sap chet cong !");
    return 0;
}