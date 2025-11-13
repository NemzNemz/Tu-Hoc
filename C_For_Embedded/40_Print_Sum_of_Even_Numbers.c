/*
Print Sum of Even Numbers
You are given an array of integers and its size. Using only pointer arithmetic:
Traverse the array
Find the sum of all even numbers
Print the sum 
❌ Do not use arr[ i ] indexing.
✅ Use only pointer movement and dereferencing.
*/

#include <stdio.h>

int sum_even_numbers(int *ptr, int n) {
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(*(ptr+i) % 2 == 0){
            temp += *(ptr+i);
        }
    }
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = sum_even_numbers(arr, n);

    printf("Sum = %d", result);

    return 0;
}