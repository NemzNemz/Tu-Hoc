/*
Tính tích các chữ số của một số
Input: n = 1234 → Output: 24 (vì 1×2×3×4=24)
*/
#include "stdio.h"
#include "stdint.h"
int tich_n(int n){
    printf("Dang xu ly %d\n", n);
    if(n < 10 ) return n;
    else return n%10 * tich_n(n/10);
}

int main(void){
    printf("%d", tich_n(12345));
    return 0;
}