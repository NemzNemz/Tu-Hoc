/*
In ra bảng cảm biến theo dạng cột, nhưng dùng \t thay vì %10s.
Name        ID      Value(V)
Temp        1       3.45
Pressure    2       1.27
Light       3       4.98

*/
#include <stdio.h>
#include <stdint.h>

int main(void){
    printf("Name        ID      Value(V)\n");
    printf("Temp\t    1 \t    3.45\n");
    printf("Dark\t    2 \t    3.45\n");
    printf("Light\t    3 \t    3.45\n");
    return 0;
}