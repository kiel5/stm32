file min.c và port_min.c sẽ đi với nhau trong mỗi dòng vđk khác nhau
file min_port chỉ định nghĩa hàm gửi data chứ chưa có hàm nhận
file uart_ring sẽ đảm nhiệm việc xử lý dữ liệu nhận uart_receive





trong hàm main: 
        gọi hàm ngắt nhận 1 byte, khi nhận 1 byte sẽ nhảy vào rxcplt rồi hàm uart_receive sẽ đẩy data vào ringbuffer
        trong while sẽ gọi hàm bootloader_handlde() để check xem có data gửi đến không, nếu có sẽ thực hiện hàm 