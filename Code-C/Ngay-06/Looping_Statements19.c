/*
Nâng cao (logic + loop control)
5. Nhập n, in ma trận n×n chứa số 1 ở đường chéo chính và 0 khác (identity matrix).
VD: n = 4
1 0 0 0 
0 1 0 0 
0 0 1 0 
0 0 0 1
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main(void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    printf("Chuan bi ve ma tran N x N ... \n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) printf(" 1 ");
            else printf(" 0 ");
        }
        printf("\n");
    }
    return 0;
}