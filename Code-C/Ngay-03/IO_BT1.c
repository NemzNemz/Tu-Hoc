/*
Yêu cầu:
Viết chương trình yêu cầu người dùng nhập tên của họ, sau đó in ra dòng:
Hello, <name>! Welcome to C programming.
Nếu dùng scanf(), thử nhập “Nguyen Van A” xem kết quả thế nào.
Sau đó sửa lại bằng fgets() để nó nhận cả họ tên có dấu cách.
*/

#include <stdio.h>
#include <stdint.h>

int main() {
    char name[110];
    printf("Nhap ten cua ban vao ! \n");
    //scanf("%s", name);
    //Scanf se chi lay tu truoc dau space, sau dau space la cut
    fgets(name, sizeof(name), stdin);
    //Fgets lay cho toi dau enter, tuc ki tu ket thuc chuoi \n
    //Bai 4 giong Bai 1, ko lam lai
    printf("Ten cua ban la %s \n", name);
    return 0;
}