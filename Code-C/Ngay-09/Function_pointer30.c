/*
Viết chương trình có hàm:
int add(int a, int b);
Yêu cầu:
Khai báo một con trỏ ptr có thể trỏ tới add.
Gán ptr trỏ tới add.
Gọi hàm add() thông qua ptr với hai số bất kỳ, in ra kết quả.
*/

#include "stdio.h"
#include "stdint.h"
//API
int add(int a, int b);
//FUNCTION
int add(int a, int b){
    return a+ b;
}

int main(void){
    //Con tro ham add
    int (*func_ptr)(int, int);
    //con tro ham bang ham add
    func_ptr = add;
    printf("%d", func_ptr(2,3));
    return 0;
} 