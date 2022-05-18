# DinoGame
- Game Dino khi mất mạng của google chrome, build lại với thư viện [SDL 2](https://www.libsdl.org/)

## Mục lục
  1. [Hướng dẫn cài đặt](##Hướng-dẫn-cài-đặt) 
  2. [Mô tả chung](##Mô-tả-chung)
  3. [Các chức năng đã cài đặt](##Chức-năng)
  4. [Kĩ thuật sử dụng](##Kĩ-thuật)
  5. [Kết luận](##Kết-luận)

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
  
  
  
