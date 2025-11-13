/*
Tạo 3 hàm tính toán:
int sum(int a, int b);
int max(int a, int b);
int min(int a, int b);
Tạo một hàm tổng quát:
int compute(int a, int b, int (*method)(int,int));
Hàm này in ra kết quả xử lý theo method.
Trong main(), thử thay đổi con trỏ method giữa 3 hàm trên và in kết quả liên tục.
*/
#include "stdio.h"
#include "stdint.h"
//API
int sum(int a, int b);
int max(int a, int b);
int min(int a, int b);
int compute(int a, int b, int (*method)(int,int));
//FUNCTION
int sum(int a, int b){
    return a+b;
}

int max(int a, int b){
    //Neu dung tra ve a ko thi tra ve b
    return a > b? a : b;
}

int min(int a, int b){
    //Neu dung tra ve a ko thi tra ve b
    return a < b? a : b;
}

int compute(int a, int b, int (*method)(int,int)){
    return method(a, b);
}

int main(void){
    //Mang 3 con tro ham
    int a = 19, b = 46;
    printf("Answer is %d ", compute(a, b, min));
    return 0;
}
