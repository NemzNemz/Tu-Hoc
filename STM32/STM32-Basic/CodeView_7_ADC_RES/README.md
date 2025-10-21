# CodeView 7 – ADC Resolution (STM32)

**Mô tả:**  
File main.c minh họa cách đọc giá trị analog từ chân ADC và chuyển đổi sang giá trị điện áp thực tế.

**Nội dung chính:**  
- Cấu hình ADC single channel hoặc continuous mode.  
- Sử dụng công thức tính điện áp từ giá trị ADC (V = (ADC_Value / 4095) × 3.3V).  
- In kết quả ra DEBUG WATCH  

**Môi trường:** STM32F103C8T6, KeilC + HAL Library.
