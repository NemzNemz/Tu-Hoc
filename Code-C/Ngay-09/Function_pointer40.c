/*
Tạo 3 hàm:
void stepA(void);
void stepB(void);
void stepC(void);
Tạo mảng void (*chain[3])(void);
Yêu cầu:
Ban đầu, gán cả 3 con trỏ vào chain.
Dựa trên biến cờ flag, bỏ qua một bước (tức là không gọi hàm ở vị trí đó).
In ra chuỗi thao tác thực tế đã thực thi.
*/

#include "stdio.h"
#include "stdint.h"
//API
void stepA(void);
void stepB(void);
void stepC(void);
//FUNCTION
void stepA(void){
    printf("Doing step 1! \n");
}
void stepB(void){
    printf("Doing step 2! \n");
}
void stepC(void){
    printf("Doing step 3! \n");
}

int main(void){
    //Mang 3 con tro ham
    uint8_t flag = 0;
    void(*func_chain[3])(void);
    func_chain[0] = stepA;
    func_chain[1] = stepB;
    func_chain[2] = stepC;
    for(uint8_t i =0; i < 3; i++){
        flag++;
        if(flag == 2) continue;
        func_chain[i]();
    }
    return 0;
}