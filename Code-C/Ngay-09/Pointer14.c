/*
Nhập số nguyên dương n, kiểm tra n có phải là số nguyên tố không.
*/
#include "stdio.h"
#include "stdint.h"
//API
uint8_t is_prime(uint8_t *ptr_a);
//FUNC
uint8_t is_prime(uint8_t *ptr_a){
    uint8_t temp = 0;
    if(*ptr_a < 2) return 0; //Ko la so nguyen to
    for(uint8_t i = 2; i * i <= *ptr_a; i++){
        if((*ptr_a) % i == 0) {
            return 0; 
        }
    }
    return 1;
}

int main(void){
    uint8_t n = 0;
    printf("Nhap 1 so nguyen duong vao !\n");
    scanf("%d", &n);
    if(is_prime(&n) == 1) printf("So nay la so nguyen to");
    else printf("Ko la so nguyen to");
    return 0;
}