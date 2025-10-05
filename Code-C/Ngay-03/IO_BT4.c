/*
Bài 5: In ký tự và mã ASCII
Nhập 1 ký tự từ bàn phím (dùng scanf("%c", &ch);).
In ra ký tự đó và mã ASCII của nó.
*/

#include <stdio.h>
#include <stdint.h>
char c;
int a;

int main(void){
    printf("Moi nhap 1 ki tu! \n");
    scanf("%c", &c);
    a = c;
    printf("Ma ASCII cua %c la %d", c, a);
    return 0;
}