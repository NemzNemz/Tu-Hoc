/*
Bài 1: Thoát nhiều tầng lặp với goto
Viết chương trình tìm hai số tự nhiên nhỏ hơn 1000 sao cho tổng và hiệu đều chia hết cho 13.
Khi tìm thấy cặp đầu tiên, thoát khỏi tất cả các vòng lặp và in ra kết quả.
Dùng goto để “thoát sâu”.
*/

#include "stdint.h"
#include "stdio.h"
int sumi, sumj;

int main(void){
    for(int i = 1; i < 1000; i++){
        for(int j = 1; j < 1000; j++){
            if(((i + j) % 13 == 0) && ((i - j) % 13 == 0)){
                sumi = i;
                sumj = j;
                goto inkq;
            }
        }
    }
    inkq:
    printf("Cap so la %d %d", sumi, sumj);
    return 0;
}