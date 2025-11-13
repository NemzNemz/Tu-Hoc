/*
Reverse an Array Using Only Pointers
You are given an array of integers and its size n.
Using only pointer arithmetic:
Reverse the array elements in-place.
Print the reversed array.
❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.
*/
#include <stdio.h>

void reverse_array(int *ptr, int n) {
    int *head = ptr;
    int *tail = ptr + (n - 1);
    int temp_head = *(ptr);
    for(int i = 0; i < n/2; i++){
        *head = *tail;
        *tail = temp_head;
        *head++;
        *tail--;
        temp_head = *head; 
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverse_array(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1){
            printf(" ");
        }
    }
    return 0;
}
