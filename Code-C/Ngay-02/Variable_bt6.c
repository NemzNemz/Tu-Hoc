/*
Bài 6 – Khởi tạo & gán giá trị
Khai báo một biến int x;.
In giá trị của x trước khi gán (sẽ là garbage value).
Sau đó gán x = 42; và in lại.
*/

#include "stdio.h"
int x;
int main(void){
    printf("Gia tri rac cua x la %d \n", x);
    x = 42;
    printf("Gia tri cua x la %d \n", x);
    return 0;
    //Co ve nhu no kha thong minh khi ko khoi tao, compiler van cho no = 0
}