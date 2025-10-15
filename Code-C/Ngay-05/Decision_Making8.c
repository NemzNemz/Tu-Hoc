/*
Nhập hai số nguyên a, b.
Nếu a bằng b → in “Equal”.
Nếu a > b
- Nếu hiệu (a - b) > 10 → in “A much greater”.
- Ngược lại → in “A slightly greater”.
Nếu a < b → in “B greater”.
*/

#include "stdio.h"
#include "stdint.h"
int a, b;

int main (void){
    printf("Nhap 2 so nguyen vao \n");
    scanf("%d %d", &a, &b);
    if(a == b) printf("2 so nay bang nhau! \n");
    if(a >b){
        if((a -b) > 10) printf("A lon hon nhieu !\n");
        else printf("A lon hon 1 chut! \n");
    }
    else
    {
       printf("B lon hon! \n");
    }
    return 0;
}