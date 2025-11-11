/*
Tạo hàm
void printArray(void *arr, int n, char type);
Có thể in ra toàn bộ mảng int, float, char…
*/
#include "stdio.h"
#include "stdint.h"
#include "string.h"
//API
void printArray(void *arr, int n, char type);
//FUNCTION
void printArray(void *arr, int n, char type){
    switch (type)
    {
    case 'i':
    {
        int *tmp_arr;
        tmp_arr = (int*)arr;
        printf("Mang int ... \n");
        for (uint8_t i = 0; i < n; i++)
        {
            printf(" %d ", tmp_arr[i]);
        }
        break;
    }
    case 'f':
    {
        float *tmp_arr;
        tmp_arr = (float*)arr;
        printf("Mang float ... \n");
        for (uint8_t i = 0; i < n; i++)
        {
            printf(" %.1f ", tmp_arr[i]);
        }
        break;
    }
    case 'c':
    {
        char *tmp_arr;
        tmp_arr = (char*)arr;
        printf("Mang char ... \n");
        for (uint8_t i = 0; i < n; i++)
        {
            printf(" %c ", tmp_arr[i]);
        }
        break;
        break;
    }
    default:
        printf("WTF!");
        break;
    }
}

int main(void){
    //LUON PHAI EP KIEU KIEU MINH MUON IN!
    char arr[5] = {'1','2','3','4','5'};
    printArray(arr, 5, 'c');
    return 0;
}
