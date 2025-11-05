/*
In từ 1 đến n (đệ quy tuyến tính)
*/
 
#include "stdio.h"
#include "stdint.h"
int in_n(uint16_t n){
    if(n == 0) return 1;
    else {
        in_n(n - 1);        //stack duoc luu 
        printf(" %d ", n); 
    }
}

int main(void){
    in_n(10);
    return 0;
}