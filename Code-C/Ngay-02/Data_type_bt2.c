/*
Bài 2 – Chia kiểu số nguyên và số thực
- Tạo hai biến int a = 5, b = 2.
- In kết quả của a/b và (float)a/b.
- Giải thích sự khác nhau.
*/

#include "stdio.h"
int a = 5, b = 2, ans;
float answ;

int main(void){
    ans = a/b; //chia  lay phan nguyen
    answ = (float)a/b;
    printf("Kq so nguyen chia lay nguyen la %d \n",ans);
    // 5/2 la chia lay nguyen, ra 2 du 1 kq = 2
    printf("Kq so thuc chia lay nguyen la %.1f \n",answ);
    // 5/2 la chia lay nguyen, voi float tuong duong 5.0 / 2.0 ra 2.5
    return 0;
}

    