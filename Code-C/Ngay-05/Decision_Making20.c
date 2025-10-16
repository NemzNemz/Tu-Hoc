/*
In các số từ 1–10, nhưng dừng lại khi gặp số 7.
*/

#include "stdio.h"
#include "stdint.h"

int main (void){
    for(int i =0; i < 10; i++){
        printf("%d \n", i);
        if(i == 7) break;
    }
    printf("Da dung lai vi gap so 7");
    return 0;
}