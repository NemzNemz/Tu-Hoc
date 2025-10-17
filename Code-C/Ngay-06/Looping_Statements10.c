/*
Nhập vào một số nguyên n. In ra chữ số đảo ngược của n.
Ví dụ: nhập 1234 → xuất 4321.
*/

#include "stdio.h"
#include "stdint.h"
int n, aws;

int main(void){
   printf("Moi nhap n vao ! \n");
   scanf("%d", &n);
   while (n != 0)
   {
    //Chia lay du
    aws = (aws * 10) + n % 10;
    printf("aws :%d \n", aws);
    n /= 10;
    printf(" n :%d \n", n);
   }
   return 0;
}