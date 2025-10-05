/*
🔹 Bài 6 – Volatile
Khai báo một biến volatile int flag = 0;
Trong một vòng while(flag == 0) cho in ra “waiting...”.
Sau vài giây, thay đổi flag bằng cách gán trong đoạn code khác (hoặc giả lập bằng input).
→ Xem sự khác biệt nếu bỏ từ volatile.

🔹 Bài 7 – Scope và Auto
Viết một hàm có 2 biến cùng tên x: một khai báo trong block, một ngoài block.
Sử dụng từ khóa auto để xem có ảnh hưởng gì tới phạm vi hay không.
*/

#include <stdio.h>
#include <stdint.h>

volatile int flag = 0; //Compiler ko duoc toi uu hoa bien nay de tranh ko phat hien su thay doi ben ngoai

int main(void){
    while (flag == 0)
    {
        printf("Waiting ... \n");
    }
    //TREN VS CODE, SE KO CO TAC DUNG NEU BO VOLATILE HOAC KHONG, NHUNG VOI RTOS HOAC STM32 INTERRUPT THI SE THAY!!
    return 0;
}