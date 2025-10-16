/*
Nhập vào một ký tự:
Nếu là chữ cái, kiểm tra xem là in hoa hay thường.
Nếu là chữ số, in “Digit”.
Ngược lại, in “Special Character”.

a - z	97 -> 122
A - Z	65 -> 90
'0' - '9'	48 -> 57
if((a >= 97 && a <= 122) || (a >= 65 && a <= 90) || (a >= 48 && a <= 57))
*/

#include "stdio.h"
#include "stdint.h"
char c;
int a, b;

int main (void){
    printf("Moi ban nhap vao 1 ki tu ! \n");
    scanf("%c", &c);
    a = c;
    if(a >= 97 && a <= 122) b = 1; //Chu thuong
    else if(a >= 65 && a <= 90) b = 2; // Chu hoa
    else if(a >= 48 && a <= 57) b = 3; // So
    else b = 4; // Ki tu dac biet
    switch (b)
    {
    case 1:
        printf("Day la chu thuong\n");
        break;
    case 2:
        printf("Day la chu in hoa\n");
        break;
    case 3:
        printf("Day la so\n");
        break;
    case 4:
        printf("Day la ky tu dac biet\n");
        break;
    }
    return 0;
    //Khong nghi ra duoc cach nao de co the long 2 switch case !
}