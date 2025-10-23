/*
Hàm float read_speed(void) nhập tốc độ.
Hàm int categorize(float spd) trả về mã:
0: “STOPPED”
1: “NORMAL” (1–60 km/h)
2: “OVERSPEED” (>60 km/h)
Hàm void display_status(int code) in thông báo theo mã.
→ Dạng này xuất hiện trong bài học LCD/UI cơ bản.
*/
#include "stdint.h"
#include "stdio.h"
float speed;
//API
float read_speed(void);
int categorize(float spd);
void display_status(int code);
//FUNCTION
float read_speed(void){
    printf("Moi nhap muc toc chay cua ban vao! \n");
    scanf("%f", &speed);
}

int categorize(float spd){  
    //STOPPED
    if(speed == 0) return 0;
    //NORMAL
    else if((speed >= 1.0) && (speed <= 60.0)) return 1;
    //OVERSPEED
    else return 2;
}

void display_status(int code){
    printf("Trang thai toc do cua ban la: \n");
    switch (categorize(speed))
    {
    case 0:
        printf("Ban co chay dau ??");
        break;
    case 1:
        printf("Toc chay dang o muc binh thuong!");
        break;
    case 2:
        printf("Toc chay vuot nguong!");
        break;
    default:
        printf("I DON'T KNOW ??");
        break;
    }
}

int main(void){
    read_speed();
    display_status(categorize(speed));
    return 0;
}
