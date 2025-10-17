/*
Trung cấp (tư duy chỉ số & điều kiện)
Nhập n, in tam giác Floyd (số tăng dần mỗi ô) kích thước n:
1
2  3
4  5  6
7  8  9  10
11 12 13 14 15
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main(void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    printf("Chuan bi in tam giac Floyd ... \n");
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            static int a = 1;
            printf(" %d  ", a++);
        }
        printf("\n");
    }
    return 0;
}