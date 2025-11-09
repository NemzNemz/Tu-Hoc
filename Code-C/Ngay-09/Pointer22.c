    /*
    Khai báo struct Point { int x, y; }. 
    Viết hàm nhận con trỏ Point và dịch chuyển nó theo vector (dx, dy) bằng phép toán con trỏ.
    */
    #include "stdio.h"
    #include "stdint.h"
    typedef struct 
    {
        int x;
        int y;
        int nx;
        int ny;
    }POINT;
    POINT point;
    //API
    void increase_pos(POINT *ptr_pt, int *n_x, int *n_y);
    void print_new_pos(POINT *ptr_pt);
    //FUNCTION
    void increase_pos(POINT *ptr_pt, int *n_x, int *n_y){
        ptr_pt->x += *n_x; 
        ptr_pt->y += *n_y;
    }

    void print_new_pos(POINT *ptr_pt){
        printf("Vi tri moi la: %d, %d", ptr_pt->x, ptr_pt->y);
    }

    int main(void){
        printf("Nhap toa do goc vao!\n");
        scanf("%d %d", &point.x, &point.y);
        printf("\n");
        printf("Nhap so cong them vao x va y!\n");
        scanf(" %d %d", &point.nx, &point.ny);
        printf("xxxxxxxx\n");
        printf("%d \n", point.x);
        printf("%d \n", point.y);
        printf("%d \n", point.nx);
        printf("%d \n", point.ny);
        increase_pos(&point, &point.nx, &point.ny);
        print_new_pos(&point);
        return 0;
    }
