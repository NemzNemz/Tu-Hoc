/*
Tạo 3 hàm:
void modA(void);
void modB(void);
void modC(void);
Mỗi hàm có biến static cục bộ riêng để nhớ số lần nó được gọi.
Trong main(), gọi xen kẽ modA(), modB(), modC() theo thứ tự bất kỳ (ví dụ: A, B, A, C, B, A).
Kết quả in ra phải thể hiện mỗi module nhớ riêng số lần mình được gọi, không ảnh hưởng nhau.
*/
#include "stdint.h"
#include "stdio.h"
int temp = 100;

void modA(void);
void modB(void);
void modC(void);

void modA(void){
    static int x = 0;
    x++;
    printf("A = %d\n", x);
}

void modB(void){
    static int x = 0;
    x++;
    printf("B = %d\n", x);
}

void modC(void){
    static int x = 0;
    x++;
    printf("C = %d\n", x);
}

int main() {
    for (uint8_t i = 1; i <= 10; i++)
    {
        modA();

    }
    for (uint8_t i = 1; i <= 6; i++)
    {

        modC();
    }
    for (uint8_t i = 1; i <= 8; i++)
    {

        modB();
    }
    return 0;
}
