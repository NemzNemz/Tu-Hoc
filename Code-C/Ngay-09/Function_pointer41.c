/*
Khai báo 1 biến ActionFunc_t action;
Cho action lần lượt trỏ đến từng hàm, và gọi chúng.
In ra trạng thái đang thực hiện (START → PROCESS → STOP).
*/
#include "stdio.h"
#include "stdint.h"
//API
void START(void);
void PROCESS(void);
void STOP(void);
//FUNCTION
void START(void){
    printf("STARTING! \n");
}

void PROCESS(void){
    printf("PROCESSING! \n");
}

void STOP(void){
    printf("STOP! \n");
}
//Khai bao 1 con tro ham moi
typedef void(*mAction)(void);

int main(void){
    mAction start = START;
    start();

    mAction process = PROCESS;
    process();

    mAction stop = STOP;
    stop();
}
