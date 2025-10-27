/* 
------------------------------------------------------------
🧩 Problem: Macro-Based Register Config Helper (16-bit)
------------------------------------------------------------
Register layout (LSB-first):
- ENABLE  : 1 bit  at bit 0
- MODE    : 2 bits at bits 1..2
- SPEED   : 3 bits at bits 3..5
- RESERVED: 2 bits at bits 6..7 (must be 0)

Task:
- Read ENABLE, MODE, SPEED (uint8_t)
- Use macros to pack a final 16-bit register value
- Leave RESERVED (6..7) = 0 (masks sẽ đảm bảo)
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>

/* Macros set từng field, có mask & shift rõ ràng */
#define FIELD_ENABLE(e)  ( (uint16_t)((!!(e) & 0x1U) << 0) )
#define FIELD_MODE(m)    ( (uint16_t)(((m)  & 0x3U) << 1) )
#define FIELD_SPEED(s)   ( (uint16_t)(((s)  & 0x7U) << 3) )

static inline uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
    uint16_t reg = 0;
    reg |= FIELD_ENABLE(enable);
    reg |= FIELD_MODE(mode);
    reg |= FIELD_SPEED(speed);
    /* Bits 6..7 tự động = 0 do không set */
    return reg;
}

int main(void) {
    uint8_t enable, mode, speed;
    if (scanf("%hhu %hhu %hhu", &enable, &mode, &speed) != 3) return 0;

    uint16_t reg = build_register(enable, mode, speed);
    printf("%u", reg);
    return 0;
}
