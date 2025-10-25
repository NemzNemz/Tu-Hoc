/*
Viết chương trình có biến toàn cục int temp = 100;
Trong main(), tạo thêm một biến int temp = 50; (shadowing).
Gọi hàm void show(void) mà bên trong hàm có printf("%d", temp);
Hỏi: show() in ra gì?
Sau đó, sửa show() để in ra biến toàn cục thực sự (gợi ý: dùng extern hoặc tên khác).
*/
#include "stdint.h"
#include "stdio.h"
int temp = 100;

void show(void);

void show(void){
    extern int temp; 
    printf("%d", temp);
}

int main() {
    int temp = 50;
    show();
    return 0;
}
//Chua sua show, no in ra 100 do no tu dong lay bien temp toan cuc lam tham tri
//Sua show de co extern, no van in ra 100 chu ko phai 50. Van nhu cu, pham vi temp la toan cuc nen show lay lam tham tri
//Tru khi show co tham so la int temp thi may ra in duoc temp50