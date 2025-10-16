/*
Viết chương trình nhận vào hai số, chỉ in “Both positive” nếu cả hai > 0 mà không gây lỗi khi nhập số âm hoặc 0.
*/

#include "stdio.h"
#include "stdint.h"
int n1, n2;

int main(void){
    printf("Nhap vao 2 so ! \n");
    scanf("%d %d", &n1, &n2);
    if(n1 && n2 > 0) printf("Both Positive \n");
    else printf("Ko hop le nhe !");
    return 0;
}