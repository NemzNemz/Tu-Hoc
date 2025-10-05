/*
Bài 8 – Phạm vi biến (Scope)
Viết chương trình có một biến int a = 10; trong main().
Tạo một block { ... } bên trong, khai báo lại int a = 20; rồi in ra giá trị trong block và ngoài block.
Quan sát sự khác biệt.
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    int a = 10;
    printf("Bien a nay bang %d \n", a);
    {
        int a = 10;
        printf("Bien a nay cung bang %d ??\n", a);
        int b = 99;
        printf("Bien b nay bang %d \n", b);
    }
    //printf("Bien b nay bang %d \n", b);
    //Dong nay se sai do pham vi cua b chi nam trong block tren kia, a trong block cung the
    //a cua ham main thi se duoc dung trong main ngoai tru block
    return 0;
}