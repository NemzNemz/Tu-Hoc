/*
🔹 Bài 5 – Typedef
Dùng typedef để tạo một kiểu mới u8 tương đương với unsigned char.
Sau đó khai báo 3 biến u8 và in kích thước của chúng.

*/

#include <stdio.h>
#include <stdint.h>
typedef unsigned char u8;
u8 a = 1;
u8 b = 10;
u8 c = 100;

int main(void){
    printf("Kich thuoc u8 a la %zu \n", sizeof(a));
    printf("Kich thuoc u8 b la %zu \n", sizeof(b));
    printf("Kich thuoc u8 c la %zu \n", sizeof(c));
    return 0;
    // Bien u8 don gian van chi co kich thuoc 1byte nhu ban dau da dinh nghia no la unsigned char
}