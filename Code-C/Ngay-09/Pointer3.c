/*
Bài 3.
Tạo biến int a = 10; và int *p = &a;.
Dùng *p để tăng giá trị a lên 3 đơn vị mà không dùng a++ hoặc a = a + 3.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 10;
    int *ptr_a = &a;

    *ptr_a += 3;
    printf("Gia tri cua a la %d", a);
    return 0;
}