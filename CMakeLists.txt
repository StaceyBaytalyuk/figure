cmake_minimum_required(VERSION 3.12)
project(figure)
set(CMAKE_CXX_STANDARD 14)

#подключает хедеры
include_directories(D:/Programs/MinGW/grx249/include)
#подключает библиотеку
link_directories(D:/Programs/MinGW/grx249/lib/win32)

add_executable(figure main.cpp Figure.cpp Figure.h)

#добавляет библиотеку при компилировании, сборке
target_link_libraries(${PROJECT_NAME} grx20)