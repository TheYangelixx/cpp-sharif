cmake_minimum_required(VERSION 3.26)
project(14041016)

set(CMAKE_CXX_STANDARD 17)

add_executable(14041016 main.cpp)

target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

#baraye estefade az conio.h
target_link_libraries(${PROJECT_NAME} -lconio)

#baraye estefade az SDL va geraphic
target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

