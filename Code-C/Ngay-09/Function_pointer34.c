/*
Tạo ba hàm độc lập:
void sayHi(void);
void sayBye(void);
void sayWait(void);
Khai báo một con trỏ hàm duy nhất có kiểu phù hợp.
Dựa trên giá trị người dùng nhập (1, 2, 3),
gán con trỏ đó trỏ tới một trong ba hàm trên,
rồi gọi nó.
*/
#include "stdio.h"
#include "stdint.h"
//API
void sayHi(void);
void sayBye(void);
void sayWait(void);
//FUNCTION
void sayHi(void){
    printf("HI NIGGA! \n");
}
void sayBye(void){
    printf("BYE NIGGA! \n");
}
void sayWait(void){
    printf("WAIT NIGGA! \n");
}

int main(void){
    void(*multi_func)(void);
    multi_func = sayHi;
    multi_func();
    
    multi_func = sayBye;
    multi_func();
    
    multi_func = sayWait;
    multi_func();
    return 0;
} 
