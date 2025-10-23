/*
Trình quản lý năng lượng
Hàm float measure_voltage(void) nhập điện áp pin.
Hàm int calc_percent(float v) quy đổi sang % (giống bài trước nhưng float).
Hàm void check_shutdown(int percent) in cảnh báo “LOW POWER” nếu <15%.
*/
#include "stdint.h"
#include "stdio.h"
//API
float measure_voltage(void);
int calc_percent(float v);
void check_shutdown(int percent);
//FUNCTION
float measure_voltage(void){
    float voltage;
    printf("Moi nhap muc dien ap cua ban vao!(0-5V) \n");
    scanf("%f", &voltage);
    return voltage;
}

int calc_percent(float v){
    int temp_percent;
    temp_percent = (v/5.0)*100.0;
    return temp_percent;
}

void check_shutdown(int percent){
    if(percent < 15) printf("LOW POWER");
    else printf("STABLE CONDITION!");
}

int main(void){
    float vol;
    int check;
    vol= measure_voltage();
    check= calc_percent(vol);
    check_shutdown(check);
    return 0;
}
