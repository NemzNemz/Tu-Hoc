/*
Bài 2 – Tiền tố và Hậu tố
Viết chương trình in ra giá trị của ++x và x++ để quan sát sự khác biệt.
*/
#include "stdio.h"
#include "stdint.h"
volatile uint8_t x = 0;
volatile uint8_t y =0;

int main(void) {
    printf("Gia tri cua x++ la %d \n", x++);
    printf("Gia tri cua ++y la %d \n", ++y);
}
//X++ la xai kq x truoc roi thuc hien +1 sau, ++Y la +1 truoc roi xai sau
