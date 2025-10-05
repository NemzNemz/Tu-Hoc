/*
Đa hệ đếm – sensor ID converter
Viết chương trình nhập vào một ID cảm biến dạng số nguyên dương.
In ra ID đó dưới 3 dạng:
Decimal   : 123
Octal     : 173
Hex (low) : 7b
Hex (UPP) : 7B
*/

#include <stdio.h>
#include <stdint.h>
uint8_t ID = 0;

int main(void){
    printf("Nhap ID Sensor vao !\n");
    scanf("%d", &ID);
    printf("ID_SS Dec la %d\n", ID);
    printf("ID_SS Octo la %o\n", ID);
    printf("ID_SS Hex Up la %x\n", ID);
    printf("ID_SS Hex Down la %X\n", ID);
    return 0;
}