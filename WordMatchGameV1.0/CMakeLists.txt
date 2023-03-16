# 规定需要的cmake最低版本是 2.8
cmake_minimum_required(VERSION 3.10)
# 工程名称是 WordMatchGameV1.0
project(WordMatchGameV1.0)
# 向工程添加存放源文件的子目录 src
# 子文件夹可以有CMakeLists.txt
add_subdirectory(src)
