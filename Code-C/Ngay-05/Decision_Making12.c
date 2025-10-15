/*
Bài 2 – Chấm điểm học sinh:
Nhập mark (0–100).
>= 85 → “Excellent”
>= 70 → “Good”
>= 50 → “Average”
< 50 → “Fail”
*/

#include "stdio.h"
#include "stdint.h"
int mark;

int main (void){
    printf("Nhap diem vao! \n");
    scanf("%d", &mark);
    if(mark >= 85) printf("Xuat sac !");
    else if(mark >= 70) printf("Tot !");
    else if(mark >= 50) printf("Trung binh !");
    else printf ("Rot !");
    return 0;
}