# DinoGame
- Game Dino khi mất mạng của google chrome, build lại với thư viện [SDL 2](https://www.libsdl.org/)

<br>
<p align="center">
  <img src="https://github.com/phucnoob/DinoGame/blob/master/demo.gif" />
</p>
<br>

## Mục lục
  1. [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt) 
  2. [Mô tả chung](#mô-tả-chung)
  3. [Chức năng đã cài đặt](#chức-năng-đã-cài-đặt)
  4. [Kĩ thuật sử dụng](#kĩ-thuật-sử-dụng)
  5. [Kết luận](#kết-luận)
  6. [Link Demo](https://youtu.be/hrEMuS6v1-4)

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
  cmake -DCMAKE_BUILD_TYPE=Release ..
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
  > Demo 
  > https://youtu.be/hrEMuS6v1-4
  - Màn hình chính của game với khủng long chạy và tránh các chướng ngại vật
  - Bật, tắt âm thanh
  - Tạm dừng trò chơi 
  - Lưu điểm cao cùng tên người chơi xuống file, tránh mất dữ liệu
  - Hiệu ứng chuyển tiếp ngày / đêm
  - Chỉnh âm lượng to nhỏ
  - Chuyển nhạc nền từ 1 file bất kì trong hệ thống

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
    - Đa luồng với SDL2
    - Dùng API filedialog
  - Các kĩ thuật lập trình 
    - Sinh số giả ngẫu nhiên theo tiêu chuẩn hiện đại của [C++11](https://en.cppreference.com/w/cpp/numeric/random)
    - Cách sử dụng const, con trỏ và tham chiếu( refenrence )
    - Cách cấp phát động và quản lí bộ nhớ
    - Log và report lỗi
    - Xử lí ngoại lệ ( cơ bản )
    - Các thư viện chuẩn của c++ stack, set, vector, list ...
    - C++ lambda
    - namespace, class, enum, static
    - C++17 filesystem
    - Kĩ thuật đệ quy
    ---
    - Các tính chất của OOP ( đóng gói, kế thừa, trừu tượng, đa hình )
    - Cách viết wrapper class
    - Design partern [Singleton](https://en.wikipedia.org/wiki/Singleton_pattern)
    - Cách chia file và quản lí file cpp, file header
    - Sử dụng cmake làm hệ thống build 
  
  ## Kết luận
  > Khi code xong con game này, em cảm thấy mình đã nắm chắc các kiến thức mà mình đã học, suy nghĩ nhằm vận dụng chúng một cách hợp li. SDL 2 chỉ là một thư viên low-level, nhưng khi có đủ thời gian và sự sáng tạo, em đã có thế tự tạo ra một phiên bản của những thứ em thấy trong các công nghệ hiện đại. Em rút ra rằng suy cho cùng thì ngôn ngữ hay công nghệ cũng chỉ là công cụ, lập trình viên mới là người thực sự giải quyết vấn đề. Từ đó em thấy nên học chắc từ gốc, không nên tìm hiểu các công nghệ quá "magic"

  [Về đầu trang](#dinogame)
