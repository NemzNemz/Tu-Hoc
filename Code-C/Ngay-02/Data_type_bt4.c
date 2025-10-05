/*
Bài 4 – Overflow
Khai báo unsigned char c = 250;
Cộng thêm 10 và in kết quả.
Giải thích tại sao số lại vòng lại (overflow).
*/

#include "stdio.h"
unsigned char c = 250;

int main(void){
    c+= 10;
    printf("Gia tri cua c la %d \n", c);
    return 0;
    //C la 1 byte tuc 8 bit, luu max 256 gia tri tu 0-255. 250+10 = 260 - 256 = 4
}


