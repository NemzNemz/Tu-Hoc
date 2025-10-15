/*
Nhập số nguyên n.
Nếu n là số dương
- Nếu n chia hết cho 2 → in “Positive even”.
- Ngược lại → in “Positive odd”.
Nếu n = 0 → in “Zero”.
Nếu n âm → in “Negative”.
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main (void){
    printf("Nhap n vao! \n");
    scanf("%d", &n);
    if(n == 0) printf("So dac biet ko am ko duong !");
    else if (n >1){
        if((n % 2) ==0){
            printf("So chan nguyen duong! \n");
        } 
        else{
            printf("So le nguyen duong ! \n");
        }
    }
    else printf("So am !");
    return 0;
}