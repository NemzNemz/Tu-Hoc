/*
Pattern with alternating rows: 
Nhập n, in n hàng, mỗi hàng có n số: dòng lẻ in 1..n, dòng chẵn in n..1. Ví dụ n=4:
1 2 3 4 <- lẻ
4 3 2 1 <- chẳn
1 2 3 4
4 3 2 1
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main(void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    printf("Chuan bi in ... \n");
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            if(i % 2 != 0){
                printf(" %d ", j);
            }
            else{
                printf(" %d ", n - j + 1);
            }
        }
        printf("\n");
    }
    return 0;
}