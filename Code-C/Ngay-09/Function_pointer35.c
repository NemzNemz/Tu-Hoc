/*
Bài 7 – Con trỏ hàm trả về giá trị
Viết hai hàm:
float temperature(void);
float pressure(void);
Sau đó viết hàm:
void showSensor(float (*sensorFunc)(void));
Nhiệm vụ: showSensor() in giá trị từ hàm được truyền vào.
*/
#include "stdio.h"
#include "stdint.h"
//API
float temperature(void);
float pressure(void);
void showSensor(float (*sensorFunc)(void));
//FUNCTION
float temperature(void){
    printf("Nhiet do bay gio là 34 do! \n");
}

float pressure(void){
    printf("Ap suat bay gio la 111hPa! \n");
}

void showSensor(float (*sensorFunc)(void)){
    sensorFunc();
}

int main(void){
    showSensor(temperature);
    showSensor(pressure);
    return 0;
} 
