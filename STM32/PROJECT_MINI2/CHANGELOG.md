# CHANGELOG – PROJECT MINI2

## D1 – 12/12/2025
- Chọn clock STM32 = 72 MHz
- Thiết lập TIM1 làm delay us/ms
- Cấu hình PA0 làm Input
- Hoàn thiện delay_us và delay_ms (uint16_t tránh tràn)
- Tạo thư viện DHT11: Start, timing, input/output, đọc 8 bit, Handle 5 byte
- Test DHT11 hoàn tất
- Chuyển DHT11 sang LIB (DHT11.c/.h)

## D2 – 13/12/2025
- Cấu hình PA1 làm output cho LED và loa
- Cấu hình PB8 làm input cho Echo (HC-SR04)
- Cấu hình PB9 làm output cho Trig (HC-SR04)
- Hoàn tất thuật toán đo khoảng cách HC-SR04 dựa trên datasheet
- Chưa chuyển code HC-SR04 thành thư viện
## D3 – 19/12/2025
- Thư viện hóa hoàn chỉnh module HC-SR04
- Xác định Servo SG90 sử dụng PWM
- Cấu hình TIM3 PWM CH1 (ARR = 20000, PSC = 71)
- TIM3-CH1 ánh xạ ra PA6 làm output cho Servo SG90
- Hiệu chỉnh CCR cho Servo SG90 (500–2500) do sai lệch phần cứng
- Hoàn tất điều khiển Servo SG90 quay chuẩn 0–180 độ
- Test logic mù hoàn tất: phát hiện vật cản, kích còi và điều khiển mở/đóng cửa
- Thư viện hóa hoàn chỉnh Servo SG90
