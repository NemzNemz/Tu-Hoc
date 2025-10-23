/*
Hàm float calc_average(float a, float b, float c) trả về trung bình.
Hàm int check_alert(float avg) trả 1 nếu avg > 80.
Trong main(), nhập 3 giá trị, in ra kết quả và thông báo nếu vượt ngưỡng.
→ Giống bộ lọc “average smoothing + threshold detection” thường thấy ở sensor.
*/
#include "stdint.h"
#include "stdio.h"
float val1, val2, val3;
//API
float calc_average(float a, float b, float c);
int check_alert(float avg);

//FUNCTION
float calc_average(float a, float b, float c){
    return ((a+b+c)/3.0);
}

int check_alert(float avg){
    float temp = calc_average(val1, val2, val3);
    if(temp > 80.0) return 1;
    else return 0;
}

int main(void){
    printf("Moi nhap 3 gia tri vao! \n");
    scanf("%f %f %f", &val1, &val2, &val3);
    if(check_alert(calc_average(val1, val2, val3))) printf("Over limit!");
    else printf("Still safe!");
    return 0;
}

