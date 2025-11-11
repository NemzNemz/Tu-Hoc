/*
Con trỏ hàm nhận hàm khác làm tham số
Viết hàm:
void runTwice(void (*func)(void));
Hàm này có nhiệm vụ gọi hàm func hai lần liên tiếp.
Viết một hàm blink() in ra "LED TOGGLE".
Gọi runTwice(blink); để thấy kết quả.
*/
#include "stdio.h"
#include "stdint.h"
//API
void blink(void);
void runTwice(void (*func)(void));
//FUNCTION
void blink(void){
    printf("LED TOGGLE! \n");
}

void runTwice(void (*func)(void)){
    //Ham chuyen nhan bat ki ham nao co tham so la void
    func();
    func();
}

int main(void){
    //Con tro ham add
    runTwice(blink);
    return 0;
} 
