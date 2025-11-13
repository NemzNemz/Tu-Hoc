/*
Simulate memcpy function Using Pointer Walk
You are given two memory buffers:
A source array of n integers
A destination array of the same size (pre-allocated, uninitialized)
Your task:
Implement the function simulate_memcpy() to copy all elements from the source to destination
✅ You must use pointer arithmetic only
❌ Do not use array indexing (arr[i])
Constraints
1 ≤ n ≤ 100
Data type: int
*/
#include <stdio.h>

void simulate_memcpy(int *dest, int *src, int n) {
    for(int i = 0; i < n; i++){
        *dest = *src;
        *dest++;
        *src++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int src[100], dest[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &src[i]);
    }

    simulate_memcpy(dest, src, n);

    for (int i = 0; i < n; i++) {
        printf("%d", dest[i]);
        if(i < n-1){
           printf(" "); 
        }
    }

    return 0;
}
