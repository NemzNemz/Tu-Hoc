/*
Hàm int count_digits(int n) dùng vòng lặp để đếm số chữ số trong n.
→ Phù hợp khi ta xử lý giá trị cảm biến nhiều chữ số để format dữ liệu.
*/
#include "stdint.h"
#include "stdio.h"
int n;
//API
int count_digits(int n);

//FUNCTION
int count_digits(int n){
    int temp =0;
    while(n != 0){
        n = n / 10;
        temp++;
    }
    return temp;
}

int main(void){
    printf("Moi nhap so cua ban vao! \n");
    scanf("%d", &n);
    printf("So do co %d chu so !", count_digits(n));
    return 0;
}
