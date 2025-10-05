/*
🔹 Bài 7 – Scope và Auto
Viết một hàm có 2 biến cùng tên x: một khai báo trong block, một ngoài block.
Sử dụng từ khóa auto để xem có ảnh hưởng gì tới phạm vi hay không.
*/

#include <stdio.h>
#include <stdint.h>

int main(void){
    auto int x = 10;
    {
        auto int x = 100;
        printf("X = %d \n", x);
    }
    printf("X = %d \n", x);
    return 0;
    //Tu khoa auto cha co y nghia gi o day, pham vi cua x ngoai va x trong la khac nhau ro ret. No khong cung voi nhau
}