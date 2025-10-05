/*
Backspace sửa lỗi (\b)
Mục tiêu: Thấy cách \b “xóa ngược” ký tự in sai (trong console).
In thử dòng sau:
printf("Loading...\b\b\b   Done!\n");
*/

#include <stdio.h>
#include <stdint.h>

int main(void){
    printf("Loading...\b\b\b   Done!\n");
    // \b xoa 1 ky tu thua o cuoi cua chuoi. 
    return 0;
}