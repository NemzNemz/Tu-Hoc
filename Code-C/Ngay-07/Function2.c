/*
Viết hàm int is_safe(float temp) trả về 1 nếu temp nằm trong khoảng 20–60 °C, ngược lại trả về 0.
main() đọc một giá trị, gọi hàm, in thông báo “Safe” hoặc “Overheat”.
→ Liên hệ thực tế: giám sát nhiệt độ module nguồn hoặc pin.
*/
#include "stdint.h"
#include "stdio.h"
float temp;
//API
int is_safe(float temp);

//FUNCTION
int is_safe(float temp){
    if((temp >= 20) && (temp <= 60)) return 1;
    else return 0;
}

int main(void){
    printf("Moi nhap nhiet do cua pin! \n");
    scanf("%f", &temp);
    if(is_safe(temp)) printf("Safe");
    else printf("Overheat!!");
    return 0;
}