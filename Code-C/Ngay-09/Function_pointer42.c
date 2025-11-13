/*
Tạo mảng 3 phần tử kiểu MathOp_t ops[3];
Gán từng phần tử trỏ đến 3 hàm tương ứng.
Sau đó duyệt mảng và in ra kết quả ops[i](5, 2).
*/
#include "stdio.h"
#include "stdint.h"
//API
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
//FUNCTION
int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a*b;
}

//Khai bao 1 con tro ham moi
typedef int(*mMath)(int, int);

int main(void){
    int a = 36, b = 63;
    //Mang con tro ham
    mMath m[3];

    m[0] = add;
    m[1] = sub;
    m[2] = mul;
    printf("Output of add, sub, mul of a and b! \n");
    for(uint8_t i = 0; i < 3; i++){
        printf(" %d \n", m[i](a, b));
    }

    return 0;
}

