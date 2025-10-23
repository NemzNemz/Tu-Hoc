/*
Kiểm tra số chẵn/lẻ
Hàm int isEven(int n) trả 1 nếu chẵn, 0 nếu lẻ.
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int isEven(int n);
//FUNCTION
int isEven(int n){
    if(n %2 != 0) return 0;
    else return 1;
}

int main(void){
    printf("Moi ban nhap n\n");
    scanf("%d", &n);
    if(isEven(n)) printf("So chan");
    else printf("So le");
    return 0;
}
