/*
In các số từ 1–10, nhưng bỏ qua số chẵn.
*/

#include "stdio.h"
#include "stdint.h"

int main (void){
    for(int i =0; i <= 10; i++){
        if(i % 2 == 0) continue;
        printf("%d \n", i);
    }
    printf("Da bo qua cac so chan");
    return 0;
}