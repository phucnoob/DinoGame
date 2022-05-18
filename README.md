# DinoGame
- Game Dino khi mất mạng của google chrome, build lại với thư viện [SDL 2](https://www.libsdl.org/)

## Mục lục
  1. [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt) 
  2. [Mô tả chung](#mô-tả-chung)
  3. [Các chức năng đã cài đặt](#chức-năng)
  4. [Kĩ thuật sử dụng](#kĩ-thuật-sử-dụng)
  5. [Kết luận](#kết-luận)

---
# Nội dung

## Hướng dẫn cài đặt
  Project này chỉ được config cho GNU/Linux, với windows, hãy tự sửa lại makefile hoặc cmake cho hợp lý
  ### Yêu cầu
  - Trình biên dịch c++17 (g++ 8.x trở lên)
  - cmake >= 3.22
  - SDL2, SDL2_image, SDL2_ttf và SDL2_mixer
  
  ### Cài trình biên dịch
  #### Ubuntu/Debian-based
  ```shell
  sudo apt install build-essential
 
  ```
  ```shell
  sudo apt install cmake
  ```
  #### Fedora/Redhat
  ```shell
  sudo dnf install make automake gcc gcc-c++ kernel-devel
 
  ```
  ```shell
  sudo dnf install cmake
  ```
  ### Cài đặt thư viện SDL 2
  #### Ubuntu/Debian-based
  ```shell
  sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
 
  ```
  #### Fedora/Redhat
  ```shell
  sudo dnf install SDL2-devel SDL2_image-devel SDL2_mixer-dev SDL2_ttf-devel
  ```
  ### Build và chạy game
  Tải project ( Download as zip) về máy hoặc dùng git
  ```
  git clone https://github.com/phucnoob/DinoGame
  ```
  Mở terminal tại folder đã tải 
  ```shell
  mkdir build
  cd build
  cmake ..
  make -j${nproc}
  ```
  Chạy game
  ```
  ./Dino
  ```
  ## Mô tả chung
  Game sử dụng nhưng ý tưởng của Chrome Dino, Khủng long chạy và né tránh các cây xương rồng, và thằn lằn bay sử dụng các phím [SPACE] và [DOWN]
  Cơ cấu trò chơi là vô tận, tốc độ di chuyển của cây xương rồng cũng như mật độ tăng dần, có chế độ chuyển ngày/ đêm
  ## Chức năng đã cài đặt
  - Màn hình chính của game với khủng long chạy và tránh các chướng ngại vật
  - Bật, tắt âm thanh
  - Tạm dừng trò chơi 
  - Lưu điểm cao cùng tên người chơi xuống file, tránh mất dữ liệu
  - Hiệu ứng chuyển tiếp ngày / đêm
  - Chỉnh âm lượng to nhỏ
  - CHuyển nhạc nên theo danh sách sẵn

  ## Kĩ thuật sử dụng
  - Các kĩ thuật với SDL2
    - Sử dụng thư viện extension để load ảnh định dạng PNG/JPG
    - Xử lí sự kiện chuột, bàn phím
    - Sử dụng SDL_RENDERER_PRESENTVSYNC để đồng bộ fps với màn hình
    - Kĩ thuật render chữ lên màn hình với SDL_ttf
    - Xử lí va chạm
    - Clip rendering ( render 1 phần ảnh )
    - Kĩ thuật xử lí nhập văn bản từ bàn phím
    - Cách xử lí file ảnh và icon ( các file resource )
    - Cách sử dụng các hàm thời gian để làm animation độc lập với FPS
  - Các kĩ thuật lập trình 
    - Sinh số giả ngẫu nhiên theo tiêu chuẩn hiện đại của [C++11](https://en.cppreference.com/w/cpp/numeric/random)
    - Cách sử dụng const, con trỏ và tham chiếu( refenrence )
    - Log và report lỗi
    - Xử lí ngoại lệ ( cơ bản )
    - Các thư viện chuẩn của c++ stack, set, vector, list ...
    - C++ lambda
    - namespace, class, enum, static
    - C++17 filesystem
    - Kĩ thuật đệ quy
    ---
    - Các tính chất của OOP ( đóng gói, kế thừa, trừu tượng, đa hình )
    - Design partern [Singleton](https://en.wikipedia.org/wiki/Singleton_pattern)
    - Cách chia file và quản lí file cpp, file header
    - Sử dụng cmake làm hệ thống build 
  
