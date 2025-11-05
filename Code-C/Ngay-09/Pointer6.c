/*
Bài 6.
Tạo hai biến x = 10, y = 20.
Tạo con trỏ p = &x, pp = &p.
Dùng pp để khiến p trỏ sang y.
Sau đó gán *p = 100.
In ra x và y
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int x = 10, y = 20;
    int *ptr = &x;
    int **pptr = &ptr;
    
    *pptr = &y;
    **pptr = 100;
    printf("Gia tri cua y bay gio la %d", **pptr);
    return 0;
}