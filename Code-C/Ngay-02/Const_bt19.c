/*
Bài 5 – Không khởi tạo const
Khai báo const int a; rồi in ra a.
🎯 Quan sát giá trị (hoặc lỗi nếu compiler bắt) và giải thích vì sao const nên luôn được khởi tạo.
*/

#include <stdio.h>
#include <stdint.h>
const int a;

int main(void){
    printf("%d \n", a);
    //Gia tri compiler dua ra la 0, tuy nhien day la 1 gia tri rac !
    //Truoc khi dung const nen khoi tao cho no 1 gia tri!
    return 0;
}