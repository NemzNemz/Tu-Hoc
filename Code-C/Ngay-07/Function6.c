/*
Hàm int is_prime(int n) trả về 1 nếu n là số nguyên tố.
Dùng vòng lặp từ 2→√n.
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int is_prime(int n);

//FUNCTION
//Cong nhận mình vẫn ko hiểu gì về toán học thuần tuý!
int is_prime(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(void){
    printf("Moi nhap n de xem no co phai la so nguyen to khong! \n");
    scanf("%d", &n);
    if(is_prime(n)) printf("So do la so nguyen to! ");
    else printf("Ko la so nguyen to!");
    return 0;
}
