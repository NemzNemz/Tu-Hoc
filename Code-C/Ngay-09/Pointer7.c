/*
Giải thích (bằng cách chạy và quan sát) tại sao đoạn sau lại lỗi:
int *p;
*p = 10;
→ Viết lại phiên bản đúng của nó.
-> Bài này bị dangling pointer. Vì int *p là 1 con trỏ NULL, tức là ko hề trỏ và bất kì vùng nhớ nào, nên 
việc gán 10 vào là ko thể vì cơ bản ko có vùng nhớ để gán
*/
#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 1;
    int *p = &a;
    *p = 10;
    printf("%d", a);
    return 0;
}
