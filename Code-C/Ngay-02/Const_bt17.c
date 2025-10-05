/*
Khai báo:
#define PI1 3.14
const float PI2 = 3.14;
In ra cả PI1 và PI2.
🎯 Giải thích sự khác nhau giữa hai cách định nghĩa (gợi ý: preprocessor vs. compiler).
*/

#include <stdint.h>
#include <stdio.h>
#define PI1 3.14
const float PI2 = 3.14;

int main(void) 
{
    printf("%.3f \n", PI1);
    //PI1 don gian la chen so 3.14 vao bat ki cho nao co PI1
    printf("%.3f \n", PI2);
    //1 hang so PI2 co dinh la 3.14
    return 0;
}