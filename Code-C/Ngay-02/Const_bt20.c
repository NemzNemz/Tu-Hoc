/*
Bài 6 – Dùng const để bảo vệ dữ liệu
Tạo hai biến:
const int maxScore = 100;
int currentScore = 75;
Tính phần trăm hoàn thành:
progress = (float)currentScore / maxScore * 100;
In ra % hoàn thành, không được gán lại maxScore.
*/

#include <stdio.h>
#include <stdint.h>
const int maxScore = 100;
int currentScore = 75;
float progress = 0.0;

int main(void){
    progress =  (float)currentScore / maxScore * 100.0;
    printf("%.3f \n", progress);
    return 0;
}