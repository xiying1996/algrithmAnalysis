cmake_minimum_required(VERSION 3.8)

project(MyAlgrithm VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制该标准
set(CMAKE_CXX_EXTENSIONS OFF)# 禁用编译器提供的扩展，使用标准的C++


# 获取src/目录下所有的*.c文件，
file(GLOB_RECURSE AGL_LIB_SRC
        src/*.cpp
        src/*.h
        )
# 编译名为agl的静态库，库的类型是第二个参数STATIC指定的。
add_library(agl STATIC ${AGL_LIB_SRC})

add_executable(test test/test.cpp)
target_link_libraries(test agl)


