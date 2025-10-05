/*
Khai báo một hằng const int limit = 100;.
In ra giá trị của nó, sau đó thử gán lại limit = 50; và quan sát lỗi compiler.
→ Giải thích vì sao lỗi đó xảy ra, và tại sao nó giúp chương trình an toàn hơn.
*/

#include <stdio.h>
#include <stdint.h>

const int limit = 100;

int main(void){
    printf("%d \n", limit);
    //limit = 99;
    //const ko the bi modified mot cach thong thuong
    return 0;
}