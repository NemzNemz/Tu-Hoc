/*
Bài 3 – Kiểm tra số chẵn lẻ bằng Bitwise
Không dùng %, hãy dùng toán tử bitwise để kiểm tra số chẵn/lẻ.
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t x = 0;

int main(void) {
    printf("Nhap so vao de kiem tra tinh chan le! \n");
    scanf("%d", &x);
    if((x & 1) != 0) printf("le !");
    else printf("chan !");
}
//AND voi 1 de check xem so do bit thap nhat la 0 hay 1. So le bit thap auto = 1, nguoc lai = 0
