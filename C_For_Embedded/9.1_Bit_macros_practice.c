/*
bạn thử tự define lại 4 macro sau trong file mới bit_macros_practice.c:
SET_BIT
CLEAR_BIT
TOGGLE_BIT
READ_BIT (hoặc IS_BIT_SET)
*/
#include <stdio.h>
#include <stdint.h>
#define SET_BIT(REG, POS)       ((REG) |= (1 << POS))
#define CLEAR_BIT(REG, POS)     ((REG) &= ~(1 << POS))
#define TOGGLE_BIT(REG, POS)    ((REG) ^= (1 << POS))
//Doc bit chu ko duoc gan &=. Gan la sai!
#define IS_BIT_SET(REG, POS)     ((REG) & (1 << POS))

int main() {
    uint8_t LED_REG = 0b00000000;
    SET_BIT(LED_REG, 2);
    SET_BIT(LED_REG, 5);
    printf("After SET : 0x%02X\n", LED_REG);

    TOGGLE_BIT(LED_REG, 3);
    printf("After TOGGLE : 0x%02X\n", LED_REG);

    CLEAR_BIT(LED_REG, 2);
    printf("After CLEAR : 0x%02X\n", LED_REG);

    if(IS_BIT_SET(LED_REG, 5)) printf("Bit 5 dang bat!");
    else printf("Bit 5 dang tat!");
    return 0;
}