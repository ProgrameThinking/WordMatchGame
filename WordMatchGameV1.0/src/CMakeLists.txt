# 本目录下源文件名称都存储在 SRC_LIST 变量中
aux_source_directory(. SRC_LIST)

# 添加工程头文件的搜索路径（多个路径空格分开）
include_directories(../include)

# 生成可执行文件的名称叫 main
# 使用存放在 SRC_LIST 变量中的源文件
add_executable(main ${SRC_LIST})

# 设置输出二进制文件的存放位置为 ${PROJECT_SOURCE_DIR}/bin
# ${PROJECT_SOURCE_DIR} 表示根目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
