# CodeView 5 – Cảm biến DHT11 (STM32)
**Mô tả:**  
File main.c minh họa cách đọc dữ liệu nhiệt độ và độ ẩm từ cảm biến DHT11 bằng kỹ thuật bit-banging sử dụng TIM và GPIO.

**Nội dung chính:**  
- Tạo xung start signal để kích hoạt DHT11  
- Đọc 5 byte dữ liệu (40 bit) theo giao thức một dây  
- Xử lý checksum và tách nhiệt độ / độ ẩm  
- Hàm DHT11_Handle() thực hiện toàn bộ quá trình đọc  

**Môi trường:** STM32F103C8T6, KeilC + HAL Library.
