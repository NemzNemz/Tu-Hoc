/*
Hàm int max3(int a, int b, int c) trả về số lớn nhất.
→ Khi làm việc với tín hiệu, ta thường cần lấy đỉnh tín hiệu (peak).
*/
#include "stdint.h"
#include "stdio.h"
int a, b, c;
//API
int max3(int a, int b, int c);

//FUNCTION
int max3(int a, int b, int c){
    if((a > b) && (a > c)) return a;
    else if (b > a && b > c) return b;
    else if((a == b) && (b == c) && (a == c)) return 0;
    else return c;
}

int main(void){
    printf("Nhap 3 so vao \n");
    printf("So thu 1: \n");
    scanf("%d", &a);
    printf("So thu 2: \n");
    scanf("%d", &b);
    printf("So thu 3: \n");
    scanf("%d", &c);
    if(max3(a, b, c) == 0) printf("3 so bang nhau");
    else printf("So lon nhat la %d ", max3(a, b, c));
    return 0;
}