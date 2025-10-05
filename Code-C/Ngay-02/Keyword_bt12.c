/*
🔹 Bài 4 – Register và tốc độ
Viết một vòng lặp tính tổng từ 1 đến 1e7.
Thử khai báo biến đếm register int i;
→ đo thời gian thực thi, rồi đổi sang int i; xem có khác không.
*/

#include <stdio.h>
#include <stdint.h>

int main(void){
    //register int z =0;
    int z =0;
    for(int i = 0; i < 10000000; i++){
        z+=i;
    }
    printf("%d \n", z);
    return 0;
    //Khong co khac biet gi, do compiler hien dai da toi uu hoa roi
}