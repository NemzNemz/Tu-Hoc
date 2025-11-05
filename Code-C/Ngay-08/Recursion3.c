/*
Tổng chữ số của một số nguyên dương
Gợi ý:
Mỗi bước tách chữ số cuối: n % 10, phần còn lại: n / 10. Base case: n < 10 thì trả về n.
*/

#include "stdio.h"
#include "stdint.h"
int sum_n_positive(uint16_t n){
    if(n < 10) return n;
    else{
        return n%10 + sum_n_positive(n/10);
    }
}

int main(void){
    printf("%d", sum_n_positive(12345));
    return 0;
}