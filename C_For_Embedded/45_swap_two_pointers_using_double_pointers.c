/*
Swap Two Pointers Using Double Pointers
You are given two pointers, each pointing to different integer variables.
Task:
Write a function that swaps the pointers themselves (not the values).
After swapping, each pointer should now point to the other’s original variable.
 You must use double pointers (int **p1, int **p2) to swap addresses.
*/

#include <stdio.h>

void swap_pointers(int **p1, int **p2) {
    int *add_temp = *p1;
    *p1 = *p2;
    *p2 = add_temp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int *p1 = &a;
    int *p2 = &b;

    swap_pointers(&p1, &p2);

    printf("%d %d", *p1, *p2);

    return 0;
}