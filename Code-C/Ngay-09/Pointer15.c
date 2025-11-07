/*
Nhập ngày, tháng, năm. Kiểm tra ngày-tháng có hợp lệ không. 
Tính thứ trong tuần của ngày đó (theo lịch Gregorian, dùng công thức Zeller).
*/
#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"
//API
void nhap(uint8_t *ptr_day, uint8_t *ptr_month, uint16_t *ptr_year);
int day_of_week(uint8_t *ptr_day, uint8_t *ptr_month, uint16_t *ptr_year);
//FUNC
void nhap(uint8_t *ptr_day, uint8_t *ptr_month, uint16_t *ptr_year){
    do {
        unsigned int d, m, y;
        
        printf("Moi nhap ngay thang nam vao! \n");
        printf("Nhap ngay: ");
        scanf("%u", &d);
        
        printf("Nhap thang: ");
        scanf("%u", &m);
        
        printf("Nhap nam: ");
        scanf("%u", &y);
        
        *ptr_day = (uint8_t)d;
        *ptr_month = (uint8_t)m;
        *ptr_year = (uint16_t)y;
        //RAT PHIEN VI KO THE SU DUNG TRUC TIEP CON TRO DO LOI SCANF VSCODE KO GIONG C ONLINE
        printf("DEBUG: %u %u %u\n", *ptr_day, *ptr_month, *ptr_year);
    } while (*ptr_day == 0 || *ptr_month == 0);
}

int day_of_week(uint8_t *ptr_day, uint8_t *ptr_month, uint16_t *ptr_year){
    uint8_t M_month;
    uint16_t M_year;
    if(*ptr_month == 1 || *ptr_month == 2){
        M_month = *ptr_month + 12;
        M_year = *ptr_year - 1;
    }
    else if(*ptr_month >= 3){
        M_month = *ptr_month;
        M_year = *ptr_year;
    }
    return ((*ptr_day) + ((13 * (M_month + 1))/5) + 
            M_year + (M_year/4) - (M_year/100) + (M_year/400)) % 7;
}

int main(void){
    uint8_t ngay, thang;
    uint16_t nam;
    nhap(&ngay, &thang, &nam);
    printf("Thu trong tuan cua ngay do la %d", day_of_week(&ngay, &thang, &nam));
    return 0;
}
