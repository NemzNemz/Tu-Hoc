/*
Tạo biến int var = 30;,
Tạo con trỏ ptr trỏ tới var và con trỏ cấp 2 pptr trỏ tới ptr.
In ra giá trị của var thông qua pptr.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int var = 30;
    int *ptr = &var;
    int **pptr = &ptr;

    printf("Gia tri cua var la %d", **pptr);
    return 0;
}