/*
Nhập một ký tự c.
Nếu là chữ cái (A–Z hoặc a–z), in “Letter”.
Nếu là chữ số (0–9), in “Digit”.
Ngược lại in “Symbol”.
a - z	97 -> 122
A - Z	65 -> 90
'0' - '9'	48 -> 57
*/

#include "stdio.h"
#include "stdint.h"
char c;

int main (void){
    printf("Nhap ky tu vao \n");
    scanf("%c", &c);
    int n = c;
    if(((n >= 97) && (n <= 122)) || ((n >= 65) && (n <= 90))) printf("Day la ki tu!");
    else if ((n >= 48) && (n <= 57)) printf("Day la so");
    else printf("Ko biet");
    return 0;
}