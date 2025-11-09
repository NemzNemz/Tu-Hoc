/*
Viết struct Student gồm id, name, score. 
Khai báo một biến kiểu Student, tạo con trỏ trỏ đến nó, 
và in ra giá trị các trường qua con trỏ.
*/
#include "stdio.h"
#include "stdint.h"
typedef struct 
{
    unsigned int id;
    unsigned char name[30];
    uint8_t score;
}STUDENT;
STUDENT student;
//API
void update_struct(STUDENT *std);
void in_tt(STUDENT *std);
//FUNCTION
void update_struct(STUDENT *std){
    printf("Moi ban nhap du lieu sinh vien!\n");
    printf("ID: ");
    scanf(" %d", &std->id);
    printf("Ho va Ten: ");
    scanf(" %20s", &std->name);
    printf("Diem so: ");
    scanf(" %d", &std->score);
}

void in_tt(STUDENT *std){
    printf("ID Sinh Vien la %d \n", std->id);
    printf("Ho Va Ten SV la %s \n", std->name);
    printf("Diem sinh vien la %d \n", std->score);;
}

int main(void){
    update_struct(&student);
    in_tt(&student);
    return 0;
}
