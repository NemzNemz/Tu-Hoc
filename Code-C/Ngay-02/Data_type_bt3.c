/*
Bài 3 – Char và ASCII
Nhập 1 ký tự từ bàn phím (scanf("%c", &ch)), in ra ký tự đó và mã ASCII của nó.
Sau đó, cộng thêm 3 vào ký tự và in ra ký tự mới (thử nhập A sẽ ra D).
*/

#include "stdio.h"
char ch;

int main(void){
    printf("Nhap 1 ky tu bat ki tu ban phim vao! \n");
    scanf("%c", &ch);
    int n = ch;
    printf("Ma ASCII cua %c la %d \n", ch, n); 
    n+=3;
    ch = n;
    printf("Ma ASCII moi cua %c la %d \n", ch, n);
    return 0;
}