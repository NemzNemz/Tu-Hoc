/*
So sánh static và auto
void test_static(void);
void test_auto(void);
Cả hai hàm đều có biến đếm, nhưng một biến dùng static int x, một biến dùng int x.
Gọi mỗi hàm 3 lần.
Quan sát sự khác biệt kết quả in.
*/
#include "stdint.h"
#include "stdio.h"
int counter = 0;  // giả sử file1.c

void test_static(void);
void test_auto(void);

void test_static(void){
    static int x = 0;
    x++;
    printf("%d", x);
}

void test_auto(void){
    int x = 0;
    x++;
    printf("%d", x);
}


int main() {
    for(int i = 1; i <=3; i++){
        test_static();
        test_auto(); //3 cai bang 1 het
    }
    return 1;
}
