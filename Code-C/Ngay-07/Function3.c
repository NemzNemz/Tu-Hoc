/*
Hàm int calc_battery(int voltage) nhận điện áp đọc được (mV), trả về phần trăm ước tính (0–100%).
Giả sử 3000 mV → 0%, 4200 mV → 100%.
→ Gợi ý: nội suy tuyến tính.
→ Dạng bài phù hợp khi ta học ADC và muốn quy đổi sang phần trăm.
*/
#include "stdint.h"
#include "stdio.h"
int vol;
//API
int calc_battery(int voltage);

//FUNCTION
int calc_battery(int voltage){
    int percent;
    percent =((voltage - 3000)/12);
    return percent;
}

int main(void){
    printf("Nhap muc dien ap cua pin vao (mili vol)! \n");
    scanf("%d", &vol);
    printf("Phan tram pin con lai cua ban la %d%%", calc_battery(vol));
    return 0;
}