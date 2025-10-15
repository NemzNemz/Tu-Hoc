/*
Nhập hai số a, b và ký tự phép toán op (+, -, *, /).
Dùng switch để thực hiện phép tương ứng.
*/

#include "stdio.h"
#include "stdint.h"
int a, b, c;

int main (void){
    printf("Nhap a va b vao! \n");
    scanf("%d %d", &a, &b);
    do{
        printf("Nhap phep toan ban muon su dung ! \n");
        printf("1. Cong \n2. Tru \n3. Nhan \n4. Chia lay nguyen \n");
        scanf("%d", &c);
        if(c < 1 || c > 4) printf("Ko hop le, moi nhap lai ! \n");
    //Ko cho phep chuong trinh chay neu ko nhap phep toan hop le!
    }while(c < 1 || c > 4);

    switch (c)
    {
    case 1:
        printf("A+B = %d", a+b);
        break;
    case 2:
        printf("A-B = %d", a-b);
        break;
    case 3:
        printf("A*B = %d", a*b);
        break;
    case 4:
        printf("A/B = %d", a/b);
        break;    
    }
    return 0;
}