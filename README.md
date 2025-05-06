# Tiểu luận môn Công Nghệ IoT:XÂY DỰNG HỆ THỐNG BÁO CHÁY PLATFORM TRIỂN KHAI TRÊN NỀN TẢNG MAGISTRALA
# Các thành viên làm tiểu luận:
Lê Đỗ Huyền Trân - 23050055
Võ Ngọc Hân – 23050056  
# Hướng dẫn sử dụng:
Phần mềm cần thiết để chạy tiểu luận:
Docker Desktop.
Docker Compose.
Arduino IDE. (Để nạp code cho ESP32).
# Bước 1: Chuẩn bị môi trường
Vào thư mục magistrala_local
Mở CMD, Git Bash, hoặc Terminal tại thư mục này.
# Bước 2: Build và chạy Docker Compose
Gõ lệnh sau để build các container, image, và volume trong Docker:
docker compose -f "docker-compose.yml" up -d --build
![image](https://github.com/user-attachments/assets/9a2a93d7-20be-4a46-8081-0408e9f5ae85)

# Bước 3: Khôi phục dữ liệu cho các volume
docker run --rm -v docker_magistralalabs-mqtt-broker-volume:/volume -v /d/backups:/backup alpine sh -c "tar -xzvf /backup/docker_magistralalabs-mqtt-broker-volume.tar.gz -C /volume" docker run --rm -v docker_magistrala_data:/volume -v /d/backups:/backup alpine sh -c "tar -xzvf /backup/docker_magistrala_data.tar.gz -C /volume" nhớ copy thư mục backups đem vào ổ d
# Bước 4: Build và chạy Docker Compose
Khi chạy dự án sử dụng: localhost:1881 dể có thể vào giao diện của magistrala để kết nối cơ sở dữ liệu: mqtt-broker của Magistrala trong phần Data source. Tiến hành tạo dashboard để có thể show dữ liệu.
