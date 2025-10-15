/*
Hiển thị menu nhỏ:
1. LED ON
2. LED OFF
3. BUZZER ON
4. EXIT
Nhập lựa chọn, in thông báo tương ứng.
*/

#include "stdio.h"
#include "stdint.h"
int perform;

int main (void){
    printf("Nhap hanh dong vao! \n");
    do{
        printf("1. LED ON \n");
        printf("2. LED OFF \n");
        printf("3. BUZZER ON \n");
        printf("4. EXIT \n");
        scanf("%d", &perform);
        if(perform > 4 || perform < 1) printf("Nhap lai cho dung ! \n");
    }while(perform > 4 || perform < 1);
    
    switch (perform)
    {
    case 1:
        printf("LED TURN ON NOW !! \n");
        break;
    case 2:
        printf("LED TURN OFF NOW !! \n");
        break;
    case 3:
        printf("BUZZER ON NOW !! \n");
        break;
    case 4:
        printf("THOAT CHUONG TRINH !! \n");
        break;
    }
    return 0;
}