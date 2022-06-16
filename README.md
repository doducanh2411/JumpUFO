# JumpUFO![UFO](https://user-images.githubusercontent.com/100185375/168901849-d64be555-2e70-4d4d-be5a-44d21f3f41b5.png)
## _Hướng dẫn cài đặt_
- Tải và cài đặt lần lượt SDL, SDL_image, SDL_ttf, SDL_mixer tại trang chủ chính thức và add và CodeBlock.
- Clone file về máy và add vào CodeBlock.
- Chạy trên CodeBlock.
## _Mô tả chung về trò chơi_
- Demo: https://www.youtube.com/watch?v=Bay1HhLP_e8
- Lấy cảm hứng từ chính trò chơi do người Việt làm Flappy Bird.
- Người chơi điều khiển UFO nhảy lên xuống bằng phím Space tránh va chạm với các tiểu hành tinh.
- Có 3 dạng tiểu hành tinh với kích cỡ khác nhau ![asteroid2](https://user-images.githubusercontent.com/100185375/168902480-bf54e0d9-024c-4351-80f8-622770c66630.png)
![asteroid1](https://user-images.githubusercontent.com/100185375/168902512-47d8d5be-ccc2-402c-a55d-7b809437d705.png)
![asteroid3](https://user-images.githubusercontent.com/100185375/168902519-958f73ab-2cc0-4f01-b2b3-28f1d74ac11e.png)


## _Các chức năng đã cài đặt_
- Điểm số: càng vượt qua nhiều tiểu hành tinh thì điểm càng cao và hiển thị lên màn hình.
- Các tiểu hành tinh sinh ra ở vị trí ngẫu nhiên và di chuyển từ bên phải màn hình vào.
- Có lưu điểm cao nhất của người chơi.
- Có thể chơi lại.
- Có nhạc nền, âm thanh khi nhảy, âm thanh khi chết.
- Có animation cho các tiểu hành tinh
### Preview
![gameplay1](https://user-images.githubusercontent.com/100185375/168907997-446c3842-18c2-43e2-8106-c995a5f7778d.png)
![gameplay2](https://user-images.githubusercontent.com/100185375/168907531-242f2ac1-6014-4c76-8288-7e12dc42b78f.png)
![gameplay3](https://user-images.githubusercontent.com/100185375/168908280-c9da2734-4147-416c-90e7-924c0e84df75.png)


## _Các kĩ thuật sử dụng_
- Thư viện SDL2.0, SDL2_image, SDL2_ttf, SDL2_mixer.
- Tạo các đối tượng: nhân vật, map, text,...
- Đọc và ghi dữ liệu file.
- Tạo menu bắt đầu.

## _Kết luận_
### Nguồn tham khảo
- Do lấy cảm hứng từ Flappy Bird nên em có tham khảo logic nhảy và di chuyển các tiểu hành tinh trên https://www.youtube.com/watch?v=h7pq9hUMnog
- Code em tự học từ https://lazyfoo.net/tutorials/SDL/
- Phần hướng đối tượng em có tham khảo từ https://phattrienphanmem123az.com/lap-trinh-game-cpp
### Hướng phát triển
- Tăng thêm tốc độ của các tiểu hành tinh khi đạt 1 số điểm nhất định.
- Thêm mạng của UFO
- Thêm các kĩ năng đặc biệt cho UFO
- ...
### Điều tâm đắc rút ra được sau khi hoàn thiện chương trình
- Tạo nền tảng tốt cho lập trình hướng đối tượng
- Biết thêm về lập trình đồ họa
- Biết về logic của game Flappy Bird
- Biết tự phát triển 1 dự án nhỏ
### Lưu ý
- Hạn chế dùng chuột nhất có thể để tránh gặp bug
### Tự đánh giá: 9/10

