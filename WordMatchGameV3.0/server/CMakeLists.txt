cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
project(WordMatchGameV3.0 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64") # Qt Kit Dir
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS
find_package(Qt5 COMPONENTS Sql REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

#将所有文件写入不同变量中
file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB FORMS "${CMAKE_CURRENT_SOURCE_DIR}/*.ui")
file(GLOB RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.qrc")

#这些生成的中间文件都会在build目录下，这样的话，编译器则不能定位由uic程序产生的诸如_ui_mainwindow.h等文件。所以，我们需要把build目录添加到包含目录中
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
#读取qt对应的头文件位置
INCLUDE_DIRECTORIES("D:\\Qt\\5.15.2\\mingw81_64\\include")
INCLUDE_DIRECTORIES("D:\\Qt\\5.15.2\\mingw81_64\\include\\QtSql")


# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


add_executable(${PROJECT_NAME}
    #WIN32 # If you need a terminal for debug, please comment this statement 
    ${SOURCES} 
    ${HEADERS} 
    ${FORMS} 
    ${RESOURCES}
) 
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Sql Qt5::Network) # Qt5 Shared Library