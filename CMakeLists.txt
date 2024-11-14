cmake_minimum_required(VERSION 3.5.0)
project(servoUp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -Wno-unused-parameter -Wno-unused-variable -Wno-overloaded-virtual ")

aux_source_directory(${CMAKE_SOURCE_DIR} SRCS_DIR)  
message(${CMAKE_SOURCE_DIR})

# 设置并行编译的线程数
set(CMAKE_BUILD_PARALLEL_LEVEL 18)


# 指定C和C++编译器路径
set(CMAKE_C_COMPILER "C:/Program Files/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw64/bin/g++.exe")

# 指定构建工具 mingw32-make 的路径
set(CMAKE_MAKE_PROGRAM "C:/Program Files/mingw64/bin/mingw32-make.exe")

# 使用 MinGW Makefiles 构建生成器
set(CMAKE_GENERATOR "MinGW Makefiles")



set (INCLUDE_PATH .)
include_directories(${INCLUDE_PATH})  

add_executable(servoUp  ${SRCS_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
