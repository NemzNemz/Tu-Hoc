/*
Giả lập 2 file bằng cách viết trong cùng một file:
int counter = 0;  // giả sử file1.c
void increment();
int main() {
    increment();
    increment();
}
và viết thêm phần thân increment() ở dưới.
Dùng extern để truy cập counter và tăng giá trị của nó.
*/
#include "stdint.h"
#include "stdio.h"
int counter = 0;  // giả sử file1.c

void increment();

int main() {
    increment();
    increment();
}

void increment(){
    extern int counter;
    counter++; 
    printf("%d\n", counter);
}