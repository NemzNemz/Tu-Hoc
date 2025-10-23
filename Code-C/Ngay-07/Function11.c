/*
Xử lý dữ liệu điện áp
Hàm float read_voltage(void) nhập điện áp.
Hàm float normalize(float v) chuẩn hóa về 0.0–1.0 trong khoảng [0V–5V].
Hàm void show_percentage(float x) in ra giá trị % (x*100).
→ Bài tập biểu diễn ADC thành giá trị phần trăm công suất, công suất quạt hoặc độ sáng LED.
*/
#include "stdint.h"
#include "stdio.h"
float voltage;
//API
float read_voltage(void);
float normalize(float v);
void show_percentage(float x);
//FUNCTION
float read_voltage(void){
    printf("Moi ban nhap dien ap cua minh vao! \n");
    scanf("%f", &voltage);
}

float normalize(float v){
    float temp = v/5.0;
    return temp;
}

void show_percentage(float x){
    printf("Muc dien ap nay tuong duong %.1f%% muc dien ap toi da!", normalize(voltage)*100);
}

int main(void){
    read_voltage();
    show_percentage(normalize(voltage));
    return 0;
}
