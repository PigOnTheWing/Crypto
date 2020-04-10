cmake_minimum_required(VERSION 3.13)
project(Crypto C)

set(CMAKE_C_STANDARD 99)

# FILE(GLOB sources ${CMAKE_SOURCE_DIR}/source/*.c)
add_executable(Crypto main.c source/CFB.c source/feistel.c source/random.c source/frequency_analysis.c source/rsa.c)
target_link_libraries(Crypto m)