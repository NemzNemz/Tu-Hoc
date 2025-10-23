/*
Hàm int read_button(void) nhập giá trị 0 hoặc 1.
Hàm int debounce(int input) kiểm tra nếu 3 lần liên tiếp nhận 1 thì xem là “nhấn hợp lệ”.
Hàm void action(int stable_state) in “TOGGLE LED” nếu hợp lệ.
→ Mô phỏng logic “debounce” cơ bản cho nhấn nút trong MCU.
*/
#include "stdint.h"
#include "stdio.h"
//API
int read_button(void);
int debounce(int input);
void action(int stable_state);
//FUNCTION
int read_button(void){
    static int button = -1;
    do
    {
        printf("Nhap gia tri tu ban phim vao(chi 0-1)! \n");
        scanf("%d", &button);
    } while (button > 1);
    return button;
}

int debounce(int input){
    static uint8_t temp = 0;
    if(input == 1){
        temp++;
    }
    if(input != 1){
        temp = 0;
        return 0;
    }
    if(temp == 3) return 1;
    return 0;
}

void action(int stable_state){
    if(stable_state == 1) printf("TOGGLE LED!");
}

int main(void){
    uint8_t input, temp;
    //Co the thay doi gia tri vong lap bang n lan!
    for(int i = 1; i <= 3; i++){
        input= read_button();
        temp = debounce(input);
    }
    if(temp) action(temp);
    else printf("INVALID!");
    return 0;
}