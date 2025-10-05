/*
Tạo một hàm counter() không có tham số.
Mỗi lần gọi hàm, in ra giá trị của một biến count và tăng nó lên.
Dùng static sao cho biến này giữ giá trị giữa các lần gọi.
Gọi hàm 3 lần trong main() để quan sát
*/

#include <stdio.h>
#include <stdint.h>

int counter(){
    static int count =0;
    return count++;
}

int main(void){
    int a = 0;
    for(int i = 0; i < 3; i++){
        a = counter();
        printf("%d \n", a);
    }
    return 0;
}