/*
Viết chương trình in ra ma trận số 5×5, trong đó mỗi ô chứa giá trị i + j.
(Ví dụ dòng đầu là 0 1 2 3 4, dòng hai là 1 2 3 4 5, …)
i/j	0	    1	    2	    3	    4
0	0+0=0	0+1=1	0+2=2	0+3=3	0+4=4
1	1+0=1	1+1=2	1+2=3	1+3=4	1+4=5
2	2+0=2	2+1=3	2+2=4	2+3=5	2+4=6
3	3+0=3	3+1=4	3+2=5	3+3=6	3+4=7
4	4+0=4	4+1=5	4+2=6	4+3=7	4+4=8
*/

#include "stdio.h"
#include "stdint.h"

int main(void){
    for(int i = 1; i<=5; i++){
        printf("%d: ", i);
        for(int j =1; j <= 5; j++){
            printf(" %d + %d = %d ", i, j, i+j);
        }
        printf("\n");
    }
}