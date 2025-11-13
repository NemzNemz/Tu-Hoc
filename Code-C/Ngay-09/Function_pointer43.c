/*
Tạo kiểu:
typedef void (*Callback_t)(uint8_t);
Viết hàm:
void repeat(uint8_t times, Callback_t cb);
Hàm này gọi cb() times lần, truyền tham số lượt chạy vào.
Viết một callback ví dụ:
void showCount(uint8_t i);
và trong main() gọi:
repeat(3, showCount);
*/
#include "stdio.h"
#include "stdint.h"
typedef void(*Callback_t)(uint8_t);
Callback_t cl;
//API
void counting(uint8_t times);
void repeat(uint8_t times, Callback_t cb);
//FUNCTION
void counting(uint8_t times){
    printf(" %d ", times);
}
void repeat(uint8_t times, Callback_t cb){
    for(uint8_t i = 0; i < times; i++){
        cb(i+1);
    }
}

int main(void){
    repeat(10, counting);
    return 0;
}
