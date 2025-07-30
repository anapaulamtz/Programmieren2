cmake_minimum_required(VERSION 3.17)
project(blatt4)

set(CMAKE_CXX_STANDARD 17)
set(DCMAKE_BUILD_TYPE Debug)
set(DCMAKE_C_FLAGS_DEBUG "-g -O0")
set(DCMAKE_CXX_FLAGS_DEBUG "-g -O0")

if(MSVC)
    add_compile_options(/W4 /EHs)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()


add_subdirectory(src)
