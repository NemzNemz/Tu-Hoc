/*
Bài 8 — Tính luỹ thừa (a^b)
Input: a = 2, b = 5 → Output: 32
*/
#include "stdio.h"
#include "stdint.h"
int luy_thua(int a, int b){
    if(b == 0) return 1;
    else return a * luy_thua(a, b-1);
}

int main(void){
    printf("%d", luy_thua(2, 5));
    return 0;
}
