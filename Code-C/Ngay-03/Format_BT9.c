/*
Bài 5: Mô phỏng log UART (embedded-style)
Mục tiêu: Gắn format specifier vào thực tế nhúng.
Giả lập việc gửi chuỗi qua UART bằng sprintf():
float temp = 23.56;
int id = 7;
char buffer[100];
*/

#include <stdio.h>
#include <stdint.h>
float temp = 23.56;
int id = 7;
char buffer[100];

int main(void){
    sprintf(buffer, "ID is %d, Temp is %.2f", id, temp);
    //Ham sprinf chi luu vao 1 mang, no ko he tra kq, muon tra kq thi phai in ra 
    printf("%s \n", buffer);
    return 0;
}