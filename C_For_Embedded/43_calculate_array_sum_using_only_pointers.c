/*
Calculate Array Sum Using Only Pointers
You are given an array of integers and its size n.
Using only pointer arithmetic:
Traverse the array
Find and print the sum of all elements.
❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.
*/

#include <stdio.h>

int calculate_sum(int *ptr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+= *ptr;
        *ptr++;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = calculate_sum(arr, n);
    printf("%d", result);

    return 0;
}