/*
Bài 2: Giá trị điện áp đo được
Nhập một giá trị điện áp float, in ra với các định dạng:
Voltage (raw)   : 3.141592
Voltage (2dp)   : 3.14
Voltage (4dp)   : 3.1416
Voltage (exp)   : 3.141592e+00
*/

#include <stdio.h>
#include <stdint.h>
float vol;

int main(void){
    printf("Nhap dien ap vao !\n");
    scanf("%f", &vol);
    printf("Raw is %f \n", vol);
    printf("Raw is %.2f \n", vol);
    printf("Raw is %.4f \n", vol);
    //In ra e+ 0000 gi do
    printf("Raw is %e \n", vol);
    return 0;
}