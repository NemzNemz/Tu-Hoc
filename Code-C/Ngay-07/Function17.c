/*
Tính giai thừa
Hàm long factorial(int n) dùng for để tính n!.
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
long factorial(int n);
//FUNCTION
long factorial(int n){
    long temp = 1;
    //0 Giai thua la 1
    if(n == 0) return temp = 1;
    for(int i =1; i <= n; i++){
        temp*=i;
    }
    return temp;
}

int main(void){
    printf("Moi ban nhap n! \n");
    scanf("%d", &n);
    printf("Giai thua cua %d la %ld", n, factorial(n));
    return 0;
}

