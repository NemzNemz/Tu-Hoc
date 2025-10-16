/*
Viết chương trình có menu như sau:
1. Shape
2. Number
Nếu chọn Shape, hiển thị:
a. Circle
b. Rectangle
Nếu chọn Number, hiển thị:
a. Even
b. Odd
Sau khi nhập 2 lựa chọn (số + ký tự), in kết quả tương ứng.
*/

#include "stdio.h"
#include "stdint.h"
int menu, answer;
char c1, c2;

int main (void){
    printf("Moi ban chon 1 lua chon! \n");
    printf("1. Shape\n2. Number\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        printf("Moi ban chon 1 lua chon! \n");
        printf("a. Circle\nb. Rectangle\n");
        //Xoa bo ki tu xuong dong /n bang cach them 1 khoang trang
        scanf(" %c", &c1);
        switch (c1)
        {
        case 'a':
            printf("Ban da chon hinh tron ! \n");
            break;
        case 'b':
            printf("Ban da chon hinh chu nhat ! \n");
            break;
        default:
            printf("Ko hop le ! \n");
            break;
        }
        break;

    case 2:
        printf("Moi ban chon 1 lua chon! \n");
        printf("a. Even\nb. Odd\n");
        //Xoa bo ki tu xuong dong /n bang cach them 1 khoang trang
        scanf(" %c", &c2);
        switch (c2)
        {
        case 'a':
            printf("Ban da chon so chan ! \n");
            break;
        case 'b':
            printf("Ban da chon so le! \n");
            break;
        default:
            printf("Ko hop le ! \n");
            break;
        }
        break;
    default:
        printf("Khong hop le ! \n");
        break;
    }
    return 0;
}