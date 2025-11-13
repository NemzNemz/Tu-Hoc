/*
Viết hàm:
void repeat(void (*action)(int), int times);
Trong đó, repeat() gọi action() nhiều lần, truyền số thứ tự lượt lặp vào mỗi lần gọi.
Ví dụ:
void blink(int i) { printf("LED blink %d\n", i); }
repeat(blink, 3);
Kết quả in:
LED blink 1
LED blink 2
LED blink 3
*/
#include "stdio.h"
#include "stdint.h"
//API
void blink(int a);
void repeat(void (*action)(int), int times);
//FUNCTION
void blink(int a){
    printf("LED is blinking %d times! \n", a);
}

void repeat(void (*action)(int), int times){
    for(uint8_t i =0; i < times; i++){
        action(i+1);
    }
}

int main(void){
    //Mang 3 con tro ham
    repeat(blink, 5);
    return 0;
}