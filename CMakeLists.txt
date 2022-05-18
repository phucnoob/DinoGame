cmake_minimum_required(VERSION 3.22)
project(Dino)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake )

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(.)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(Dino main.cpp utils/tinyfiledialogs.cpp guikit/Texture.cpp guikit/Texture.h utils/Graphics.cpp utils/Graphics.h miscellaneous/RuntimeError.cpp miscellaneous/RuntimeError.h text/StaticText.cpp text/StaticText.h text/Font.cpp text/Font.h constants/Constants.cpp constants/Constants.h constants/Color.h text/DynamicText.cpp text/DynamicText.h utils/Random.cpp utils/Random.h guikit/AnimationTexture.cpp guikit/AnimationTexture.h utils/Timer.cpp utils/Timer.h screen/Screen.cpp screen/Screen.h utils/Vector2.h input/InputManager.cpp input/InputManager.h gameplay/Game.cpp gameplay/Game.h screen/ScreenManager.cpp screen/ScreenManager.h screen/StartScreen.cpp screen/StartScreen.h screen/GameScreen.cpp screen/GameScreen.h screen/TestScreen.cpp screen/TestScreen.h guikit/BaseButton.cpp guikit/BaseButton.h gameplay/Road.cpp gameplay/Road.h gameplay/Score.cpp gameplay/Score.h gameplay/Cloud.cpp gameplay/Cloud.h gameplay/Cactus.cpp gameplay/Cactus.h gameplay/EnemyManager.cpp gameplay/EnemyManager.h gameplay/Ptero.cpp gameplay/Ptero.h gameplay/Dino.cpp gameplay/Dino.h audio/AudioManager.cpp audio/AudioManager.h guikit/ToogleButton.cpp guikit/ToogleButton.h utils/Utils.cpp utils/Utils.h guikit/Button.cpp guikit/Button.h gameplay/Leaderboard.cpp gameplay/Leaderboard.h guikit/TextInput.cpp guikit/TextInput.h guikit/Slider.cpp guikit/Slider.h screen/OptionsScreen.cpp screen/OptionsScreen.h)
target_link_libraries(Dino SDL2::Main SDL2::Mixer SDL2::Image SDL2::TTF Threads::Threads)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
