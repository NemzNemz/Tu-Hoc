/*
Viết ba hàm:
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
Yêu cầu: gọi operate(a,b,add) → cộng, operate(a,b,sub) → trừ, v.v.
*/
#include "stdio.h"
#include "stdint.h"
//API
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int operate(int a, int b, int (*op)(int,int));
//FUNCTION
int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}
int operate(int a, int b, int (*op)(int,int)){
    return op(a, b);
}

int main(void){
    //Chi truyen ham, ko can truyen tham so
    printf(" %d ", operate(19, 2, add));
    return 0;
} 