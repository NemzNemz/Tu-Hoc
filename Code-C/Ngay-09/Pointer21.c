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
    unsigned char name;
    uint8_t score;
}STU;/*
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

STUDENT student ={
    .id     = 0,
    .name   = "0",
    .score  = 0
};

int main(void){

    return 0;
}
