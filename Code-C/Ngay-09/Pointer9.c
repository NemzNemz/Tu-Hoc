/*
Tạo chương trình tính tổng của hai số nguyên,
nhưng không được truy cập trực tiếp biến — chỉ dùng con trỏ để đọc và ghi dữ liệu.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 5, b = 15;
    int *ptr_a = &a;
    int *ptr_b = &b;

    printf("Tong cua a va b la %d", (*ptr_a) + (*ptr_b));
    return 0;
}