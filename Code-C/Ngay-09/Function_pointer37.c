/*
Viết 3 hàm:
void readTemp(void);
void readHumid(void);
void readPress(void);
Sau đó khai báo mảng 3 con trỏ hàm (void (*sensorOps[3])(void);)
Mỗi phần tử trỏ đến một trong 3 hàm trên.
*/
#include "stdio.h"
#include "stdint.h"
//API
void readTemp(void);
void readHumid(void);
void readPress(void);
//FUNCTION
void readTemp(void){
    printf("Temp is hot! \n");
}

void readHumid(void){
    printf("Humid is hight! \n");
}

void readPress(void){
    printf("Pressure is low! \n");
}

int main(void){
    //Mang 3 con tro ham
    void(*arr_ptr_func[3])(void);
    arr_ptr_func[0] = readTemp;
    arr_ptr_func[1] = readHumid;
    arr_ptr_func[2] = readPress;
    for(uint8_t i =0; i < 3; i++){
        arr_ptr_func[i]();
    }
    return 0;
}