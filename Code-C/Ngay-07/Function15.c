/*
Tính tổng từ 1 đến n bằng hàm
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int tong_n(int n);
//FUNCTION
int tong_n(int n){
    int temp = 0;
    for(int i =1; i <=n ; i++){
        temp+=i;
    }
    return temp;
}

int main(void){
    printf("Moi ban nhap n\n");
    scanf("%d", &n);
    printf("Tong tu 1 den n la %d", tong_n(n));
    return 0;
}
