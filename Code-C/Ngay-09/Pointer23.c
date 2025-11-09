/*
struct Data { int arr[5]; }. 
Viết hàm in các phần tử arr bằng cách dùng con trỏ (không dùng chỉ số).
*/
#include "stdio.h"
#include "stdint.h"
typedef struct 
{
    int arr[5];
}DATA;
DATA dt;
//API
void update_arr(DATA *ptr_dtt);
void arr_out(DATA *ptr_dtt);
//FUNCTION
void update_arr(DATA *ptr_dtt){
    printf("Nhap 5 so vao chuoi! \n");
    for(uint8_t i =0; i< 5; i++){
        scanf("%d", &ptr_dtt->arr[i]);
    }
}

void arr_out(DATA *ptr_dtt){
    printf("Bat dau in 5 so da nhap!\n");
    for(uint8_t i =0; i< 5; i++){
        //su dung phep toan tren con tro
        printf(" %d ", *(ptr_dtt->arr+i));
    }
}

int main(void){
    update_arr(&dt);
    arr_out(&dt);
    return 0;
}