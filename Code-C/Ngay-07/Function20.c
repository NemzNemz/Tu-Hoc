/*
Tính tổng các chữ số của n
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int sum_digits(int n);
//FUNCTION
int sum_digits(int n){
    uint8_t temp =0;
    while (n!=0)
    {
        temp = temp + n%10;
        n/=10;
    }
    return temp;
    
}

int main(void){
    printf("Moi ban nhap n! \n");
    scanf("%d", &n);
    printf("So do tong la %d!", sum_digits(n));
}

