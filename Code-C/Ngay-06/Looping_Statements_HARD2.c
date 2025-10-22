/*
Bài 2: Bỏ qua số nguyên tố trong vòng lặp
Duyệt các số từ 2 đến 50.
Nếu gặp số nguyên tố, không in ra (dùng continue).
Nếu gặp số chia hết cho 5, kết thúc vòng lặp ngay lập tức (dùng break).
Những số còn lại thì in bình thường.
*/

#include "stdint.h"
#include "stdio.h"
uint8_t check_nt_below51(int num){
    uint8_t temp = 0;
    if(num < 2) return 0;
    if(num == 2) return 1;
    for(uint8_t i = 2; i*i <= num; i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

int main(void){
    printf("Chuan bi check so nguyen to tu 2 toi 5 chuc! \n");
    printf("Neu la so nt, ko in ra! \n");
    for(uint8_t i = 2; i <=50; i++){
        if(check_nt_below51(i)) continue;
        else {
            printf(" %d ", i);
            if(i % 5 == 0) break;
        }
    }
}