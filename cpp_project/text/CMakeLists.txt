cmake_minimum_required(VERSION 3.10)
project(hello)
# 生成 hello.exe 文件 依赖于main.cpp printGG.cpp
add_executable(hello main.cpp printGG.cpp aaa.h)