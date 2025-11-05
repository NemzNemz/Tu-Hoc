/*
Bài 7 — In chữ số đảo ngược
Input: n = 1234 → Output: 4 3 2 1
*/
#include "stdio.h"
#include "stdint.h"
int in_n_nguoc(int n){
    printf("Dang xu ly %d\n", n);
    if(n < 10 ) return n;
    else{
        printf("%d\n", n%10);
        in_n_nguoc(n/10);
    }
}

int main(void){
    printf("%d", in_n_nguoc(12345));
    return 0;
}