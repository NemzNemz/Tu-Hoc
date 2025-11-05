/*
Bài 9 — Tổng phần tử mảng bằng recursion
Input: a[] = {1, 3, 5, 7}, n = 4 → Output: 16
*/
#include "stdio.h"
#include "stdint.h"
int tong_mang(int arr[], int n){
    if(n == 0) return n;
    else{
        return arr[n-1] + tong_mang(arr, n-1);
    }

}

int main(void){
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("%d", tong_mang(arr, n));
    return 0;
}

