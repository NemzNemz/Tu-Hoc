/*
Hàm float c_to_f(float c) → (c * 9/5) + 32.
main() nhập giá trị °C, gọi hàm, in °F.
→ Bài kinh điển, dễ mở rộng khi dùng sensor DS18B20 hoặc DHT11.
*/
#include "stdint.h"
#include "stdio.h"
float celsius;
//API
float c_to_f(float c);

//FUNCTION
float c_to_f(float c){
    return ((c * 9/5) + 32);
}

int main(void){
    printf("Nhap nhiet do cua ban vao (C) \n");
    scanf("%f", &celsius);
    printf("Nhiet do o Fahrenheit la %.2f.F", c_to_f(celsius));
    return 0;
}