/*
Hoán đổi hành vi
Có hai hàm:
void hello(void);
void goodbye(void);
Khai báo con trỏ hàm phù hợp.
Gán con trỏ lần lượt trỏ đến hello và goodbye.
Gọi chúng trong main() để in ra hai câu khác nhau mà không dùng if hay switch.
*/
#include "stdio.h"
#include "stdint.h"
//API
void hello(void);
void goodbye(void);
//FUNCTION
void hello(void){
    printf("Hello NIGGAAAA! \n");
}

void goodbye(void){
    printf("Goodbye NIGGAAAA! \n");
}

int main(void){
    //Con tro ham kieu void
    void (*func_ptr)(void);
    func_ptr = hello;
    func_ptr();

    func_ptr = goodbye;
    func_ptr();
    return 0;
}   
