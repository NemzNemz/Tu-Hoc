/*
Nhập một số n.
In “Divisible by 5” nếu n chia hết cho 5.
Nếu không, in “Not divisible by 5”.
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main (void){
    printf("Nhap so nguyen vao \n");
    scanf("%d", &n);
    if(n % 5 == 0) printf("Divisible by 5");
    else printf("Not divisible by 5");
    return 0;
}