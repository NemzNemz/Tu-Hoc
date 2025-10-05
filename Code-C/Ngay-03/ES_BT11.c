/*
UART xuống dòng đúng chuẩn (\r\n)
Mục tiêu: Hiểu sự khác biệt giữa \n và \r\n trong serial output.
Giả lập gửi 3 dòng log cảm biến, mỗi dòng phải kết thúc bằng \r\n như trên thiết bị thực.
Ví dụ:
ID:01 | Temp:23.56*C
ID:02 | Temp:27.12*C
ID:03 | Temp:25.44*C
*/

#include <stdio.h>
#include <stdint.h>
float temp[3] = {25.41, 29.1, 32.8};
int id[3] ={001, 002, 003};
char buffer[3][100];


int main(void){
    for(int i =0; i < 3; i++){
        sprintf(buffer[i],"ID:%d | Temp:%.2f \r\n", id[i], temp[i]);
    }

    for(int i =0; i < 3; i++){
        printf("%s", buffer[i]);
    }
    return 0;
}