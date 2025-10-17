/*
Hiển thị menu đơn giản:
1. Cong
2. Tru
3. Nhan
4. Chia
5. Thoat
Người dùng chọn mục, nhập hai số và chương trình thực hiện phép tính tương ứng. Sau khi in kết quả, menu xuất hiện lại cho đến khi chọn “5. Thoat”.
*/

#include "stdio.h"
#include "stdint.h"
int menu, a, b, answ;

int main(void){
    do
    {
        printf("Moi chon lenh trong danh sach sau! \n");
        printf("1. Cong\n2. Tru\n3. Nhan\n4. Chia\n5. Thoat \n");
        scanf("%d", &menu);
        if(menu != 5){
            printf("Ban da lua chon phuong an %d \n", menu);
            printf("Moi thuc hien nhap vao a va b \n");
            printf("A ");
            scanf("%d", &a);
            printf("B ");
            scanf("%d", &b);
            switch (menu)
            {
            case 1:
                printf("Ket qua cua phep cong la %d\n", a+b);
                break;
            case 2:
                printf("Ket qua cua phep tru la %d\n", a-b);
                break;
            case 3:
                printf("Ket qua cua phep nhan la %d\n", a*b);
                break;
            case 4:
                printf("Ket qua cua phep chia lay nguyen la %d\n", a/b);
                break;
            }
        }
    } while (menu != 5);
    printf("Da thoat chuong trinh !");
    return 0;
}