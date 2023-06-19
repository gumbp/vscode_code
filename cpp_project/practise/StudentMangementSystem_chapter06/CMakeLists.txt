cmake_minimum_required(VERSION 3.10)
project(main)
# 生成 hello.exe 文件 依赖于main.cpp printGG.cpp
add_executable(main  main.cpp interface.cpp  Person_implement.cpp)      