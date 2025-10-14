/*
Bài 7 – Kiểm tra phạm vi
Kiểm tra xem một số x có nằm trong khoảng [10, 50] hay không, chỉ dùng toán tử logic (&&, ||, !).
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t a = 0;

int main(void) {
    printf("Nhap vao so a \n");
    scanf("%d", &a);
    if(!(a <10) && !(a >50)){
        printf("So nay thuoc pham vi 10-50 ! \n");
    }
    else printf("So nay ko thuoc pham vi 10-50 ! \n");
    //Dung ! de so sanh, neu a ko be hon 10 va ko lon hon 50 thi so a trong 10-50
}