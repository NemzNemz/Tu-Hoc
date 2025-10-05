/*
Bài 9 – Kích thước biến bằng sizeof
Khai báo các biến: int, float, double, char.
In ra kích thước của từng biến bằng sizeof
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h> //Danh cho %zu

char c = 'A';
int a = 1;
float pi = 3.14;
double pi2 = 6.28;
long long aa = 999999999999999LL;

int main(void){
    printf("Kich thuoc cua char la %zu byte \n", sizeof(c));
    printf("Kich thuoc cua int la %zu byte \n", sizeof(a));
    printf("Kich thuoc cua float la %zu byte \n", sizeof(pi));
    printf("Kich thuoc cua double la %zu byte \n", sizeof(pi2));
    printf("Kich thuoc cua long long la %zu byte \n", sizeof(aa));
    return 0;
}