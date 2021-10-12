cmake_minimum_required(VERSION 3.10.2)
project(Lab_4_Project)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB calculator.cpp)

add_library(calculator STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main calculator)
