/*
Nhập số kW điện tiêu thụ, tính chi phí theo bậc thang như sau:
100 kW đầu: 500đ/kW
Trên 100 đến 250: 800đ/kW
Trên 250 đến 350: 1000đ/kW
Trên 350: 1500đ/kW
*/
#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"
//API
void nhap(uint16_t *ptr_kWh);
uint32_t tinh_tien_dien(uint16_t *ptr_kWh);
//FUNC
void nhap(uint16_t *ptr_kWh){
    unsigned int elec;
    printf("Moi ban nhap so dien cua ban da su dung!\n");
    scanf("%d", &elec);
    *ptr_kWh = (uint16_t)elec;
}
uint32_t tinh_tien_dien(uint16_t *ptr_kWh){
    if(*ptr_kWh <= 100) return 500 * (*ptr_kWh);
    else if((*ptr_kWh) > 100 &&(*ptr_kWh) <= 250) return (500 * 100) + (800 * (*ptr_kWh - 100));
    else if((*ptr_kWh) > 250 &&(*ptr_kWh) <= 350) return (500 * 100) + (800 * 150) + (1000 * (*ptr_kWh - 250));
    else if((*ptr_kWh) > 350) return (500 * 100) + (800 * 150) + (1000 * 100) + (1500 * (*ptr_kWh - 350));
}

int main(void){
    uint16_t so_dien;
    nhap(&so_dien);
    printf("So tien dien la %d.VND", tinh_tien_dien(&so_dien));
    return 0;
}