/*
In ra tam giác sao phải (right-angled triangle) có chiều cao 6.
Dòng 1 có 1 sao, dòng 2 có 2 sao, …
*
**
***
****
*****
******
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i = 1; i<=6; i++){
        printf("%d: ", i);
        for(int j =1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}
