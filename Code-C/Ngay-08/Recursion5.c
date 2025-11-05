/*
Bài 5 — In dãy đảo ngược (từ n xuống 1)
Input: n = 5 → Output: 5 4 3 2 1
*/
#include "stdio.h"
#include "stdint.h"
int in_n_nguoc(int n){
    printf("Dang xu ly %d\n", n);
    if(n == 0) return n;
    else {
        printf(" %d ", n);
        in_n_nguoc(n-1);
    }
}

int main(void){
    printf("%d", in_n_nguoc(5));
    return 0;
}