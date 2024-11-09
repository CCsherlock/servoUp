cmake_minimum_required(VERSION 3.5.0)
project(servoUp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -Wno-unused-parameter -Wno-unused-variable -Wno-overloaded-virtual ")

aux_source_directory(${CMAKE_SOURCE_DIR} SRCS_DIR)  
message(${CMAKE_SOURCE_DIR})


set (INCLUDE_PATH .)
include_directories(${INCLUDE_PATH})  

add_executable(servoUp  ${SRCS_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
