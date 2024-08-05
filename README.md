#LƯU Ý KHI ĐỌC DỮ LIỆU TỪ CẢM BIẾN SICK THÔNG QUA IO-LINK

+ Format chung của chuẩn PDI48 (32BIT)/(8BIT)/(8BIT)
+ Tuy nhiên ở một số cảm biến 32bit có thể là kiểu int, uint, hoặc float (đọc từ datasheet của nhà sản xuất). Cho nên không thể viết 1 hàm chuyển đổi data chung cho tất cả các thiết bị của SICK.

Format Data của một số thiết bị SICK

<CENTER>

![alt text](Picture/WTM10L.png)
<p>Hình 1: WTM10L</p><br>

![alt text](Picture/MPB10.png)
<p>Hình 2: MPB10</p><br>

![alt text](Picture/OD2000.png)
<p>Hình 3: OD2000</p><br>
</CENTER>