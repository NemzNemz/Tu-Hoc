/*
Bài 2 – Xác định ngày trong tuần:
Nhập số nguyên day (1–7).
1 → “Monday”
2 → “Tuesday”
…
7 → “Sunday”
Nếu ngoài khoảng, in “Invalid day”.
*/
#include "stdio.h"
#include "stdint.h"
int day;

int main (void){
    printf("Nhap ngay vao! \n");
    do{
        printf("1. Thu 2 \n2. Thu 3 \n3. Thu 4 \n4. Thu 5 \n5. Thu 6 \n6. Thu 7 \n7. Chu Nhat \n");
        scanf("%d", &day);
        if(day > 7 || day < 1) printf("Ngay ko hop le, vui long nhap lai dum !\n");
    }while(day > 7 || day < 1);
    switch (day)
    {
    case 1:
        printf("Day la thu 2! \n");
        break;
    case 2:
        printf("Day la thu 3! \n");
        break;
    case 3:
        printf("Day la thu 4! \n");
        break;
    case 4:
        printf("Day la thu 5! \n");
        break;
    case 5:
        printf("Day la thu 6! \n");
        break;
    case 6:
        printf("Day la thu 7! \n");
        break;
    case 7:
        printf("Day la Chu Nhat! \n");
        break;
    }
    return 0;
}