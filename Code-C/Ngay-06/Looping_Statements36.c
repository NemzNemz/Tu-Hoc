/*
while–do-while:
In ra n dòng, mỗi dòng in ra số từ 1 đến số dòng đó, 
nhưng đảm bảo dòng nào cũng in ít nhất một số (dù i > j từ đầu).
*/

#include "stdio.h"
#include "stdint.h"
uint8_t n;

int main(void){
    printf("Moi nhap n! \n");
    scanf("%d", &n);
    uint8_t line = 1;
    while (line <= n)
    {
        uint8_t k = 1;
        do{
            printf(" %d ", k);
            k++;
        }while(k <= line);
        printf("\n");
        line++;
    }
    return 0;
}