/*
Tạo ba hàm dạng:
void step1(void);
void step2(void);
void step3(void);
Sau đó khai báo ba con trỏ hàm riêng biệt,
mỗi con trỏ trỏ đến một bước tương ứng.
Trong main(), gọi lần lượt ba con trỏ này theo đúng thứ tự,
để mô phỏng “chuỗi thao tác” (ví dụ như “khởi tạo → xử lý → kết thúc”).
*/
#include "stdio.h"
#include "stdint.h"
//API
void step1(void);
void step2(void);
void step3(void);
void (*ptr_step1)(void);
void (*ptr_step2)(void);
void (*ptr_step3)(void);
//FUNCTION
void step1(void){
    printf("Doing something first! \n");
}
void step2(void){
    printf("Doing something for step2! \n");
}
void step3(void){
    printf("Doing something for step3! \n");
}

int main(void){
    ptr_step1 = step1;
    ptr_step1();

    ptr_step2 = step2;
    ptr_step2();

    ptr_step3 = step3;
    ptr_step3();
    return 0;
}
