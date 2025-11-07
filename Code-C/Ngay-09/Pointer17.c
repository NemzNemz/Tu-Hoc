/*
Nhập số tiền cần đổi (nguyên dương). 
Tìm số tờ ít nhất cho mỗi mệnh giá (500k, 200k, 100k, 50k, 20k, 10k, 5k, 2k, 1k).
*/
#include "stdio.h"
#include "stdint.h"
//API
void nhap_tien(unsigned int *ptr_m);
unsigned int tinh_tien(unsigned int *ptr_m, unsigned int ptr_arr_m[]);
//FUNC
void nhap_tien(unsigned int *ptr_m){
    do
    {
        printf("Moi ban nhap so tien ban hien co! \n");
        scanf("%u", ptr_m);
    } while (*ptr_m <=0);
    printf("So tien hien tai la %d\n", *ptr_m);
}

unsigned int tinh_tien(unsigned int *ptr_m, unsigned int arr_m[]){
    unsigned int paper_m[9] = {0};
    unsigned int old_M = *ptr_m;
    unsigned int new_M;
    for(uint8_t i =0; i <9 ; i++){
        paper_m[i] = old_M / (arr_m[i]);
        new_M = old_M % (arr_m[i]);
        //Update tien moi
        old_M = new_M;
    }
    printf("Phan tich menh gia:\n");
    for (uint8_t i = 0; i < 9; i++) {
        if (paper_m[i] > 0) {
            printf("%d to %d.VND\n", paper_m[i], arr_m[i]);
        }
    }
}

int main(void){
    unsigned int money;
    unsigned int arr_m[9] ={500, 200, 100, 50, 20, 10, 5, 2, 1}; 
    nhap_tien(&money);
    tinh_tien(&money, arr_m);
    return 0;
}
