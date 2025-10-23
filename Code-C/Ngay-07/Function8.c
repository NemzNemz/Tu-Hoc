/*
Viết chương trình gồm 3 hàm:
float read_temp(void);          // đọc giá trị nhiệt độ (giả lập nhập từ bàn phím)
int check_status(float temp);   // trả 1 nếu > 50°C, ngược lại 0
void control_fan(int status);   // in “FAN ON” nếu status = 1, “FAN OFF” nếu = 0
Trong main(), gọi 3 hàm theo chuỗi.
*/
#include "stdint.h"
#include "stdio.h"
int temp;
//API
float read_temp(void);  
int check_status(float temp); 
void control_fan(int status); 

//FUNCTION
float read_temp(void){
    printf("Moi ban nhap nhiet do cua phong vao! \n");
    scanf("%d", &temp);
}

int check_status(float temp){
    //Mo quat
    if(temp > 50) return 1; 
    //Tat quat
    else return 0;
}

void control_fan(int status){
    if(status) printf("Nong a, mo quat day!");
    else printf("Ko du nhiet do de mo quat");
}

int main(void){
    read_temp();
    control_fan(check_status(temp));
    return 0;
}
