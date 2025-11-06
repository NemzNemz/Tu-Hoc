/*
Viết chương trình nhập a, b. 
Giải phương trình bậc nhất ax + b = 0. In nghiệm (hoặc kết luận vô nghiệm/vô định nếu có).
*/

#include "stdio.h"
#include "stdint.h"
//API
int ptb1(int *ptr_a, int *ptr_b, double *ptr_aws);
//FUNC
int ptb1(int *ptr_a, int *ptr_b, double *ptr_aws){
    if (*ptr_a != 0){
        *ptr_aws = -((double)*ptr_b)/((double)*ptr_a);  //Nghiem duy nhat
        return 2;
    }
    else if(*ptr_a == 0 && *ptr_b == 0) return 1; //Phuong trinh vo so nghiem
    else if(*ptr_a == 0 && *ptr_b != 0) return 0; //Phuong trinh vo nghiem
    
}

int main(void){
    int a, b, c;
    double res;
    printf("Moi nhap 2 so vao! \n");
    scanf("%d", &a);
    scanf("%d", &b);
    c = ptb1(&a, &b, &res);

    switch(c)
    {
    case 0:
        printf("Phuong trinh vo nghiem! \n");
        break;

    case 1:
        printf("Phuong trinh vo so nghiem! \n");
        break;
    
    case 2:
        printf("Ket qua cua phuong trinh la %.2llf", res);
        break;
    }
    return 0;
}