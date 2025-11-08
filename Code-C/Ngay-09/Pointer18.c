/*
Nhập một số nguyên dương < 4000, in ra số La Mã tương ứng.
1	    I
5	    V
10	    X
50	    L
100	    C
500	    D
1000	M
*/
#include "stdio.h"
#include "stdint.h"
//API
void nhap(unsigned int *ptr_m);
void digit_to_roman(unsigned char *romanc[], unsigned int digit[], unsigned int *value);
//FUNC
void nhap(unsigned int *ptr_m){
    do
    {
        printf("Moi nhap gia tri vao!\n");
        scanf(" %d", ptr_m);
    } while (*ptr_m <= 0);
    printf("Gia tri vua nhap la %d, dang quy doi thanh so La Ma!\n", *ptr_m);
}

void digit_to_roman(unsigned char *romanc[], unsigned int digit[], unsigned int *value){
    uint16_t temp = *value;
    for(uint8_t i =0; i <= 13; i++){
        while (temp >= digit[i])
        {
            printf("%s", romanc[i]);
            temp = temp - digit[i];
        }
    }
}


int main(void){
    //Mang cac con tro! can học sau
    unsigned char *roman_c[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV", "I"};
    unsigned int digit_c[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    unsigned int value;
    nhap(&value);
    digit_to_roman(roman_c, digit_c, &value);
    //printf("%s", roman_c[1]);
    return 0;
}