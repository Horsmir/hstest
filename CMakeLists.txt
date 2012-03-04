project(hstest)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(hstest_SRCS hstest.cpp main.cpp)
qt4_automoc(${hstest_SRCS})
add_executable(hstest ${hstest_SRCS})
target_link_libraries(hstest ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
