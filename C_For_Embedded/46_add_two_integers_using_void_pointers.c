/*
 Add Two Integers Using Void Pointers
Write a function that receives two void pointers, each pointing to an integer. 
Return sum of the two integer.
Note: Function arguments are passed as void * and can’t be changed.
*/

#include <stdio.h>

int add_two_void_pointers(void *a, void *b) {
    int *pa;
    pa = (int*)a;

    int *pb;
    pb = (int*)b;

    int sum = 0;
    return sum = *pa + *pb;
}

int main() {
    int x, y;
    printf("Nhap hai so nguyen (x y): ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Loi nhap lieu!\n");
        return 1;
    }

    int result = add_two_void_pointers(&x, &y);
    printf("Ket qua: %d\n", result);

    return 0;
}