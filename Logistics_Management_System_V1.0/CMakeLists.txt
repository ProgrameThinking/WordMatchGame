# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.25)
#项目名称, 参数值是 main, 该命令表示项目的名称是 main
project(Logistics_Management_System_V2.0)
# 目标程序名
aux_source_directory(. DIR_TOOT_SRCS)
# 显示指定使用的C编译器 
set(CMAKE_C20_FLAGS "${CMAKE_C20_FLAGS} -g")

# 引入mysql库
#声明头文件路径
set(INC_DIR D:\\MySQL\\MySQLServer8.0\\include)
#声明链接库路径
set(LINK_DIR D:\\MySQL\\MySQLServer8.0\\lib)
#引入头文件
include_directories(${INC_DIR})
#引入库文件
link_directories(${LINK_DIR})
link_libraries(libmysql)
# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_TOOT_SRCS})
#将第三方库链接在一起
target_link_libraries(Logistics_Management_System_V2.0 libmysql)