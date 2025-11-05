/*
Fibonacci
0	1	1	2	3	5	8	13	21	34	55	89	144	233	377	610
*/
#include "stdio.h"
#include "stdint.h"
int Fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    } 
}

int main(void){
    for(int i = 0; i < 13; i++){
        printf("%d ", Fibonacci(i));
    }
    return 0;
}
