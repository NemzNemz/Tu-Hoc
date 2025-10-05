/*
Bài 7 – Kết hợp const với biểu thức
const int base = 10;
const int height = 5;
const float area = (base * height) / 2.0;
🎯 In ra diện tích tam giác và đảm bảo không có phép gán lại nào cho base, height, hoặc area.
*/

#include <stdio.h>
#include <stdint.h>

const int base = 10;
const int height = 5;
/*const float area = (base * height) / 2.0;
Neu const o day, phep tinh se ko the thuc hien do no xem area = (cong thuc), 
ko phai ket qua, no cung ko tinh kq luon
*/
int main(void){
    const float area = (base * height) / 2.0;
    printf("%.3f \n", area);
    return 0;
}