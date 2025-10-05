/*
Bài 1 – Kích thước và giới hạn
- Viết chương trình in ra:
- Kích thước (bytes) của các kiểu: char, int, float, double, long long.
- Giá trị cực tiểu và cực đại của int và unsigned int (dùng <limits.h>).

Bài 2 – Chia kiểu số nguyên và số thực
- Tạo hai biến int a = 5, b = 2.
- In kết quả của a/b và (float)a/b.
- Giải thích sự khác nhau.

Bài 3 – Char và ASCII
- Nhập 1 ký tự từ bàn phím (scanf("%c", &ch)), in ra ký tự đó và mã ASCII của nó.
- Sau đó, cộng thêm 3 vào ký tự và in ra ký tự mới (thử nhập A sẽ ra D).

Bài 4 – Overflow
- Khai báo unsigned char c = 250;
- Cộng thêm 10 và in kết quả.
- Giải thích tại sao số lại vòng lại (overflow).

Bài 5 – Kết hợp kiểu dữ liệu
- Khai báo int x = 10; double y = 3.5;
- Tính x + y, x / y, y / x.
- In kết quả và kiểu dữ liệu thực tế được dùng trong mỗi phép toán.
*/

#include "stdio.h"
char c = 'A';
int a = 1;
float pi = 3.14;
double pi2 = 6.28;
long long aa = 999999999999999LL;

int main(void){
    printf("Kich thuoc cua char la %lld byte \n", sizeof(c));
    printf("Kich thuoc cua int la %lld byte \n", sizeof(a));
    printf("Kich thuoc cua float la %lld byte \n", sizeof(pi));
    printf("Kich thuoc cua double la %lld byte \n", sizeof(pi2));
    printf("Kich thuoc cua long long la %lld byte \n", sizeof(aa));
    return 0;
}


