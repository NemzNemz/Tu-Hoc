/*
Bài 3 – Tính diện tích hình tròn
Khai báo:
const float PI = 3.14159;
float r = 5.0;
Tính diện tích hình tròn S=PI∗r∗r và in ra kết quả.
🎯 Xác minh rằng PI không bị gán lại được.
*/

#include <stdio.h>
#include <stdint.h>
const float PI = 3.14159;
float r = 5.0;

int main(void){
    float answ = PI*r*r;
    printf("dt hinh tron la %.3f \n", answ);

    //PI = 3.99999; 
    //Dong nay se sai do const ko the gan lai
    return 0;
}