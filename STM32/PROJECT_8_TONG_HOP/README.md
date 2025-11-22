PROJECT 8 – TỔNG HỢP: ADC + DHT11 + LCD 16x02 + PWM LED

Dự án tổng hợp nhiều ngoại vi STM32F103 bao gồm ADC, PWM, Timer, giao tiếp LCD 16x02 và cảm biến DHT11.
Toàn bộ giao thức cho LCD và DHT11 đều được xây dựng thủ công, không sử dụng thư viện ngoài.

1. Chức năng chính
(1) Đọc biến trở bằng ADC
Sử dụng ADC1 Channel 8.
Quy đổi điện áp theo công thức:
V = (ADC / 4095) * 3.3V
Chuyển ADC sang giá trị PWM (0 → 65535).
Xuất PWM qua TIM2_CH3 để điều khiển độ sáng LED.

(2) Đọc nhiệt độ & độ ẩm bằng DHT11
Toàn bộ giao thức bit-banging được tự viết:
Tạo xung start 18ms
Chuyển GPIO Input/Output thủ công
Đọc từng bit bằng delay_us và phân tích mức xung 50us
Nhận 40 bit dữ liệu gồm:
Humidity Int
Humidity Dec
Temperature Int
Temperature Dec
Checksum

(3) Giao tiếp LCD 16x02 chế độ 8-bit
Tự xây dựng đầy đủ hàm điều khiển:
lcd_send_command()
lcd_write()
lcd_go_to_xy()
lcd_printf_string()
Hàm Function Set, Entry Mode, Display ON/OFF, Clear Display,...

Hiển thị:
Dòng 1: PWM value
Dòng 2: TEMP – HUM

(4) Điều khiển LED theo nhiệt độ
LED bật nếu int_temp > 31°C.
LED tắt nếu dưới ngưỡng.

(5) Hàm delay_us tự xây dựng bằng TIM1
Dựa trên CNT của TIM1 (polling).
Đảm bảo độ chính xác cần thiết cho giao thức LCD và DHT11.

2. Ảnh minh họa mạch

![PROJECT_8_TONG_HOP Breadboard](./z7252566799306_043bf802b35eb10ef86327f3d4349c87.jpg)

4. File quan trọng
main.c – chứa toàn bộ ADC + PWM + LCD + DHT11 + delay_us
Không sử dụng bất kỳ library LCD hay DHT11 có sẵn.
Các hàm được nhóm theo từng module để dễ mở rộng.
5. Ghi chú
Mốc PWM là 16-bit (0–65535).
LCD sử dụng 8-bit song song, phải đảm bảo timing chuẩn (t_AS, t_DSW, t_H…).
DHT11 yêu cầu độ chính xác delay_us cao, vì vậy delay phải dựa vào timer thay vì HAL_Delay.
