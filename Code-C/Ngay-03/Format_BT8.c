/*
In log dữ liệu cảm biến có định dạng
Nhập thông tin của 3 cảm biến: tên, ID, giá trị (float).
In ra dưới dạng bảng:
| Name       | ID   | Value (V) |
|-------------|------|-----------|
| TempSensor  | 00001|     3.56  |
| Pressure    | 00002|     1.24  |
| Light       | 00003|     5.00  |
*/

#include <stdio.h>
#include <stdint.h>
char name_of_ss[3][20];
int ID_of_ss[3];
float val_of_ss[3];

int main(void){
    for(int i = 0; i < 3; i++){
        printf("Nhap ten cam bien vao !\n");
        scanf("%s", name_of_ss[i]);
        printf("Nhap ID cam bien vao !\n");  
        scanf("%d", &ID_of_ss[i]);
        printf("Nhap gia tri cam bien vao !\n");
        scanf("%f", &val_of_ss[i]);
    }
    printf("| Name       | ID   | Value (V) | \n");

    for(int i = 0; i < 3; i++){
        printf("| %-10s |%d   |%.2f |\n", name_of_ss[i], ID_of_ss[i], val_of_ss[i]);
    }
    //Bai nay co tinh su dung mang de on tap 1 chut
    return 0;
}