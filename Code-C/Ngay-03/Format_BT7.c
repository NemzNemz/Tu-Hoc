/*
Bài 3: Địa chỉ bộ nhớ debug
Khai báo 3 biến:
int sensor_val = 100;
float temp = 25.3;
char status = 'A';
In ra màn hình giá trị và địa chỉ bộ nhớ của từng biến.
*/

#include <stdio.h>
#include <stdint.h>
int sensor_val = 100;
float temp = 25.3;
char status = 'A';

int main(void){
    printf("Gia tri cua sensor_val la %d \n", sensor_val);
    printf("Gia tri cua temp la %.1f \n", temp);
    printf("Gia tri cua status la %c \n", status);

    printf("Dia chi cua sensor_val la %p \n", (void*)&sensor_val);
    printf("Dia chi cua temp la %p \n", (void*)&temp);
    printf("Dia chi cua status la %p \n", (void*)&status);
    return 0;
}