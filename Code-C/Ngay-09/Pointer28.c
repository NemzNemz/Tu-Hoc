/*
Tính tổng mảng bất kỳ kiểu
Viết hàm double sum(void *arr, int n, char type);
– Nếu type = 'i' thì cộng các int.
– Nếu type = 'f' thì cộng các float.
– Nếu type = 'd' thì cộng các double.
Duyệt mảng bằng phép toán con trỏ và cast phù hợp.
*/

#include "stdio.h"
#include "stdint.h"
#include "string.h"
//API
double sum(void *arr, int n, char type);
//FUNCTION
double sum(void *arr, int n, char type){
    double asw = 0;
    switch (type)
    {
    case 'i':
    {
        int *arr_temp;
        arr_temp = (int*)arr;
        for(uint8_t i =0; i < n; i++){
            asw += *(arr_temp+i);
        }
        return asw;
        break;
    }
    case 'f':
    {
        float *arr_temp;
        arr_temp = (float*)arr;
        for(uint8_t i =0; i < n; i++){
            asw += *(arr_temp+i);
        }
        return asw;
        break;
    }
    case 'd':
    {
        double *arr_temp; 
        arr_temp = (double*)arr;
        for(uint8_t i =0; i < n; i++){
            asw += *(arr_temp+i);
        }
        return asw;
        break;
    }
    default:
        printf("Invalid type!\n");
        break;
    }
}

int main(void){
    float arr[5] = {1,2,3,4,5};
    //LUON PHAI EP KIEU KIEU MINH MUON IN!
    printf("%.2f", (float)sum(arr, 5, 'f'));
    return 0;
}
