/*
Bộ chuyển đổi đơn vị nhiệt độ
Hàm float c_to_k(float c) đổi sang Kelvin.
Hàm float c_to_f(float c) đổi sang Fahrenheit.
Hàm void show_all(float c) in đồng thời cả 3 giá trị (C, F, K).
*/
#include "stdint.h"
#include "stdio.h"
//API
float c_to_k(float c);
float c_to_f(float c);
void show_all(float c);
//FUNCTION
float c_to_k(float c){
    return c+ 273.15;
}

float c_to_f(float c){
    return (c *1.8)+32;
}

void show_all(float c){
    printf("Nhiet do C, F, K la: \n");
    printf("%.1fC, %.1fF, %.1fK", c, c_to_f(c), c_to_k(c));
}

int main(void){
    float c;
    printf("Moi ban nhap do C vao! \n");
    scanf("%f", &c);
    show_all(c);
    return 0;
}
