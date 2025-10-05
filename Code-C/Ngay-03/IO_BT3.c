/*
Bài 3: Tính chu vi và diện tích hình chữ nhật
Nhập chiều dài và chiều rộng (kiểu float).
In ra kết quả với 2 chữ số thập phân.
*/

#include <stdio.h>
#include <stdint.h>
float dai, rong;

int main(void){
    printf("Moi nhap chieu dai va rong ! \n");
    printf("Chieu dai \n");
    scanf("%f", &dai);
    printf("Chieu rong \n");
    scanf("%f", &rong);
    printf("Chu vi hcn la %.3f \n", (dai + rong)*2);
    printf("Dien tich hcn la %.3f \n", dai * rong);
    return 0;
}