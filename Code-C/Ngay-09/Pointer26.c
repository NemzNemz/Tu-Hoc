/*
Viết hàm
void printValue(void *ptr, char type);
Trong đó type có thể là 'i', 'f', 'c'. Hàm sẽ in ra giá trị tương ứng sau khi ép kiểu phù hợp.
*/
#include "stdio.h"
#include "stdint.h"
//API
void printValue(void *ptr, char type);
//FUNCTION
void printValue(void *ptr, char type){
    switch (type)
    {
    case 'i':
    {
        int *ptr_i;
        ptr_i = (int*)ptr;
        printf("Gia tri cua bien la %d\n", *ptr_i);
        break;
    }
    case 'f':
    {
        float *ptr_f;
        ptr_f = (float*)ptr;
        printf("Gia tri cua bien la %.1f\n", *ptr_f);
        break;
    }
    case 'c':
    {
        char *ptr_c;
        ptr_c = (char*)ptr;
        printf("Gia tri cua bien la %c\n", *ptr_c);
        break;
    }
    default:
        printf("Khong hieu!");
        break;
    }
}

int main(void){
    int in = 10;
    float fo = 3.14;
    char ch = 'd';
    printValue(&in, 'i');
    printValue(&fo, 'f');
    printValue(&ch, 'c');
    return 0;
}