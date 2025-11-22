PROJECT 8 – Tổng Hợp: ADC + DHT11 + LCD 16x02 + PWM LED

Dự án tổng hợp ngoại vi STM32F103 bao gồm ADC, PWM, Timer, LCD 16x02 và cảm biến DHT11.
Toàn bộ giao thức LCD và DHT11 đều được xây dựng thủ công, không dựa trên bất kỳ library ngoài nào.

1. Chức năng chính
1.1. Đọc biến trở bằng ADC

Sử dụng ADC1 Channel 8

Công thức chuyển đổi điện áp:

V = (ADC / 4095) * 3.3V


Chuyển giá trị ADC sang PWM (0–65535)

Xuất PWM qua TIM2_CH3 điều khiển độ sáng LED

1.2. Đọc nhiệt độ và độ ẩm bằng DHT11

Giao thức bit-banging tự xây dựng hoàn toàn:

Tạo xung Start 18 ms

Chuyển GPIO Input/Output thủ công

delay_us() dùng TIM1 CNT polling

Đọc từng bit bằng xung 50 us

Tổng cộng 40 bit dữ liệu:

Byte	Ý Nghĩa
1	Humidity Integer
2	Humidity Decimal
3	Temperature Integer
4	Temperature Decimal
5	Checksum
1.3. Điều khiển LCD 16x02 chế độ 8-bit

Tự code toàn bộ giao thức điều khiển LCD:

lcd_send_command()

lcd_write()

lcd_go_to_xy()

lcd_printf_string()

Function Set, Entry Mode Set, Display ON/OFF, Clear Display

Timing tuân thủ yêu cầu LCD (t_AS, t_DSW, t_H…)

Nội dung hiển thị:

Dòng 1: PWM_VALUE

Dòng 2: TEMP – HUM

1.4. Điều khiển LED theo nhiệt độ

LED bật nếu int_temp > 31°C

LED tắt nếu ≤ 31°C

1.5. Hàm delay_us tự tạo bằng TIM1

Dựa trên CNT TIM1 để tạo độ trễ microsecond chính xác – cần thiết cho LCD và DHT11.

2. Ảnh minh họa mạch thực tế

Ảnh lấy trực tiếp từ thí nghiệm thực tế của project:

![PROJECT_8_TONG_HOP Breadboard](./z7252566799306_043bf802b35eb10ef86327f3d4349c87.jpg)

3. File chính

main.c – chứa toàn bộ logic:

ADC → PWM

Giao thức DHT11

Giao tiếp LCD

delay_us bằng TIM1

Điều khiển LED ngưỡng nhiệt độ

Không sử dụng thư viện LCD hoặc DHT11 có sẵn. Tất cả giao thức đều được viết thủ công.

4. Ghi chú kỹ thuật

PWM sử dụng độ phân giải 16-bit (0 → 65535)

ADC dùng sampling time 1.5 cycles (tối thiểu)

LCD chế độ 8-bit song song yêu cầu timing chặt chẽ → cần delay_us chính xác

DHT11 nhạy với jitter thời gian → dùng CNT Timer tốt hơn HAL_Delay

5. Mục tiêu học tập 

Project giúp rèn luyện:

Cách kết hợp nhiều ngoại vi trong một ứng dụng thực

Cách viết giao thức custom không phụ thuộc HAL

Cách quản lý thời gian chính xác bằng timer

Tư duy xử lý tín hiệu cảm biến theo thời gian thực
