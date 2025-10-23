/*
Đếm số chữ số
Hàm int count_digits(int n) – đếm số chữ số của n
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int count_digits(int n);
//FUNCTION
int count_digits(int n){
    uint8_t temp =0;
    while (n!=0)
    {
        n/=10;
        temp++;
    }
    return temp;
    
}

int main(void){
    printf("Moi ban nhap n! \n");
    scanf("%d", &n);
    printf("So do co %d chu so!", count_digits(n));
}
