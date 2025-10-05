/*
Bài tập tổng hợp – Giả lập hiển thị LCD 16x2
Mô phỏng cách dữ liệu được in lên màn hình LCD 16x2, nơi mỗi dòng chỉ chứa tối đa 16 ký tự.
Hiểu cơ chế xuống dòng (\n), trở về đầu dòng (\r) và cắt chuỗi hiển thị khi vượt giới hạn.
🧩 Mô tả bài toán
Viết chương trình hiển thị thông tin cảm biến lên LCD 16x2, mỗi dòng chỉ chứa tối đa 16 ký tự.
Dòng 1: "TEMP: 25.34*C"
Dòng 2: "PRESS: 101.23kPa"
Nếu giá trị thay đổi, chương trình ghi đè lại dòng cũ (mô phỏng \r – quay đầu dòng).
*/
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
float temp[3] = {25.41, 29.1, 32.8};
float press[3] ={101.1, 202.2, 303.3};
char buffer[3][100];

int main(void){
    for(int i =0; i < 3; i++){
        sprintf(buffer[i], "TEMP: %.2f*C\nPRESS: %.1fkPa \r\n", temp[i], press[i]);
    }
    for(int i =0; i < 3; i++){
        printf("%s", buffer[i]);
        Sleep(1000);
        printf("100%% complete");
    }
    return 0;
}