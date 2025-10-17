/*
Tính tổng các chữ số của một số nguyên n.
Ví dụ: n = 532 → tổng = 10.
*/

#include "stdio.h"
#include "stdint.h"
int n, aws;

int main(void){
    printf("Moi nhap n vao ! \n");
    scanf("%d", &n);
    while (n != 0)
    {
        aws += n % 10;
        n /= 10; 
    }
    printf("%d", aws);
    return 0;
}