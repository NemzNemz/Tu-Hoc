/*
Viết chương trình gồm một hàm float calc_average(int a, int b, int c) 
nhận ba giá trị đo và trả về giá trị trung bình.
Trong main(), nhập ba số nguyên, gọi hàm và in kết quả.
→ Mô phỏng phép đọc ADC từ 3 cảm biến nhiệt độ, lấy giá trị trung bình làm đầu ra.
*/
#include "stdint.h"
#include "stdio.h"
int val1, val2, val3;
//API
float cal_avg(int a, int b, int c);

//FUNCTION
float cal_avg(int a, int b, int c){
    float temp =((a+b+c)/3.0);
    return temp;
}

int main(void){
    printf("Moi nhap 3 gia tri cua sensor! \n");
    printf("Val1: \n");
    scanf("%d", &val1);
    printf("Val2: \n");
    scanf("%d", &val2);
    printf("Val3: \n");
    scanf("%d", &val3);
    printf("Gia tri trung binh la %.2f ", cal_avg(val1, val2, val3));
    return 0;
}