/*
Kiem tra so nguyen to.
*/

#include "stdio.h"
#include "stdint.h"
int n, aws, count = 0;

int main(void){
    start:
    printf("Moi nhap n de xem co phai so nguyen to hay ko \n");
    scanf("%d", &n);
    if(n == 0 || n == 1){
        printf("Ko phai so hop le! vui long nhap lai! \n");
        goto start;
    }
    else{
        for(int i = 2; i <= n; i++){
            if(n % i == 0) {
                count++;
                if(i != n /i) count ++;
            }
        }
        if(count == 2) printf("%d la so hop le", n);
        else printf("Ko phai so nguyen to");
    }
    //Bai nay co le nen doi hoc ham thi nen lam dang in so nguyen to tu 2 -> n
    return 0;
}