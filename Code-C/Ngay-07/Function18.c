/*
Kiểm tra số đối xứng (palindrome)
Viết hàm int is_palindrome(int n) trả 1 nếu n đối xứng (ví dụ 121, 1221) và 0 nếu không.
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int is_palindrome(int n);
//FUNCTION
int is_palindrome(int n){
    int temp = 0, temp2 = n;
    while (n!=0)
    {
        temp = (temp*10) + n%10;
        n/=10;
    }
    if(temp == temp2) return 1;
    else return 0;
}

int main(void){
    printf("Moi ban nhap n! \n");
    scanf("%d", &n);
    if(is_palindrome(n)) printf("Day la so doi xung");
    else printf("Ko la so doi xung!");
}
