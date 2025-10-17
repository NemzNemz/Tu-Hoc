/*
Nâng cao (logic + loop control)
Nhập n, in tam giác số nghịch (giảm) — ví dụ n=4:
4 4 4 4
4 4 4
4 4
4
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main(void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    printf("Chuan bi ve tam giac nghich ... \n");
    for(int i = 0; i < n; i++){
        for(int j = n - i; j > 0; j--){
            printf(" %d ", n);
            //printf("j = %d ", j);
        }
        printf("\n");
    }
    return 0;
}