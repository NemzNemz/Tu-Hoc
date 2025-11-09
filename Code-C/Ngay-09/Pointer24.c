/*
Khai báo struct Student list[3], 
viết hàm void printAll(struct Student *ptr, int n) để in qua phép toán con trỏ.
*/
#include "stdio.h"
#include "stdint.h"
typedef struct 
{
    unsigned int id;
    unsigned char name[30];
    uint8_t score;
}STUDENT;
STUDENT student[3];
//API
void update_info(STUDENT std[]);
void info_out(STUDENT std[]);
//FUNCTION
void update_info(STUDENT std[]){
    printf("Moi nhap thong tin cua 3 sinh vien! \n");
    for (uint8_t i = 0; i < 3; i++)
    {
        printf("Nhap ID hoc sinh thu %d\n", i+1);
        scanf("%d", &std[i].id);

        printf("Nhap ten hoc sinh thu %d\n", i+1);
        scanf("%30s", &std[i].name);

        printf("Nhap diem hoc sinh thu %d\n", i+1);
        scanf("%d", &std[i].score);
    }
}

void info_out(STUDENT std[]){
    printf("Dang xuat thong tin cua 3 sinh vien! \n");
    for (uint8_t i = 0; i < 3; i++)
    {
        printf("ID hoc sinh thu %d: %d\n", i+1, std[i].id);
        printf("Ten hoc sinh thu %d: %s\n", i+1, std[i].name);
        printf("Diem hoc sinh thu %d: %d\n", i+1, std[i].score);
    }
}

int main(void){
    update_info(student);
    info_out(student);
    return 0;
}