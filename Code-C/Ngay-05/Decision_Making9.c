/*
Nhập 3 số điểm math, phys, chem.
Nếu tất cả ≥ 50 → in “Pass”.
Nếu có môn nào < 50 →
- Nếu tổng 3 môn ≥ 120 → in “Retake one subject”.
- Ngược lại → in “Fail”.
*/

#include "stdio.h"
#include "stdint.h"
int math, phys , chem, sum;

int main (void){
    printf("Nhap diem 3 mon toan ly hoa vao! \n");
    scanf("%d %d %d", &math, &phys, &chem);
    if((math >= 50) && (phys >=50) && (chem >= 50)) printf("Pass!");
    else if ((math < 50) || (phys < 50) || (chem < 50)){
        int sum = math + phys + chem;
        if(sum >= 120) printf("Hoc lai 1 mon bat ki");
        else printf("Rot !");
    }
    return 0;
}