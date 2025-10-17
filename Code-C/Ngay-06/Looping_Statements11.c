/*
Viết chương trình yêu cầu người dùng nhập một số trong khoảng 1–10.
Nếu nhập sai, báo lỗi và yêu cầu nhập lại cho đến khi đúng
*/

#include "stdio.h"
#include "stdint.h"
int n;

int main(void){
    do
    {
        printf("Moi nhap n vao! (1-10)\n");
        scanf("%d", &n);
        if((n <= 0) || (n > 10)) {
            printf("Sai, nhap lai! \n");
        }
    } while (n <= 0 || n > 10);

    printf("%d ", n);
    return 0;
}