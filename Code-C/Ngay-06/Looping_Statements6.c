/*
In ra dãy số Fibonacci gồm 10 phần tử đầu tiên.
*/

#include "stdio.h"
#include "stdint.h"
int a = 0, b = 1, n = 0;

int main(void){
    for(int i = 0; i < 10; i++){
        n = a + b;
        printf("%d ", n);
        a = b;
        b = n;
    }
    return 0;
}