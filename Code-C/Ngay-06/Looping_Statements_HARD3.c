/*
Bài 3: return trong hàm phụ
Viết hàm int find_first_even(int n) nhận vào số nguyên dương n, liên tục nhập các số từ bàn phím cho đến khi 
gặp số chẵn đầu tiên (dùng vòng lặp while/for tuỳ ý).
Khi gặp số chẵn, trả về số đó (dùng return để thoát hàm).
Nếu không có số nào chẵn, trả về -1.
*/
#include "stdint.h"
#include "stdio.h"
uint8_t res;
//n o day la vo dung
int find_first_even(int n){
    printf("Moi ban nhap so lien tuc! \n");
    int input;
    do
    {
        scanf("%d", &input);
    } while (input % 2 != 0);
    if(input % 2 == 0) return input;
    else return -1;
}

int main(void){
    res = find_first_even(0);
    printf("So chan vua nhap la %d", res);
    return 0;
}