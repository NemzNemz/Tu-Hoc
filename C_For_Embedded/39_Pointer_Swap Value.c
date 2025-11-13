/*
You are given two integers a and b. 
Write a function that swaps their values using pointers. 
You must pass the addresses of both variables to the function. 
After swapping, print their updated values in main().
*/
#include <stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    swap(&a, &b);

    printf("a = %d ", a);
    printf("b = %d", b);

    return 0;
}