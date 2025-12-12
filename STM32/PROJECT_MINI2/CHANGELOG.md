# CHANGELOG – PROJECT MINI2

## D1 – 12/12/2025
- Chọn clock STM32 = 72 MHz
- Thiết lập TIM1 làm delay us/ms
- Cấu hình PA0 làm Input
- Hoàn thiện delay_us và delay_ms (uint16_t tránh tràn)
- Tạo thư viện DHT11: Start, timing, input/output, đọc 8 bit, Handle 5 byte
- Test DHT11 hoàn tất
- Chuyển DHT11 sang LIB (DHT11.c/.h)

