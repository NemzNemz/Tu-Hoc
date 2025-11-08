/*
Nhập một số nguyên dương, kiểm tra xem số đó có phải số thuận nghịch (Palindrome) không.
*/
#include "stdio.h"
#include "stdint.h"
//API
void nhap(unsigned int *ptr_v);
unsigned int check_palindrome(unsigned int val);
//FUNC
void nhap(unsigned int *ptr_v){
    do
    {
        printf("Moi nhap gia tri vao!\n");
        scanf(" %d", ptr_v);
    } while (*ptr_v <= 0);
    printf("Gia tri vua nhap la %d\n", *ptr_v);
}

unsigned int check_palindrome(unsigned int val){
    printf("Dang kiem tra so doi xung! \n");
    uint16_t temp = 0, temp2 = val;
    while (val != 0)
    {
        temp = (temp *10) + val % 10;
        val /= 10;
        printf("%d\n", temp);
    }
    if(temp == temp2) return 1;
    else return 0;;
}

int main(void){
    unsigned int var;
    nhap(&var);
    if(check_palindrome(var)) printf("Day la so doi xung!");
    else printf("Day ko la so doi xung!");
    return 0;
}