project(hstester-client)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstester-client_SRCS reportview.cpp report.cpp testthread.cpp ${share_SRC} testmanager.cpp dlgconfig.cpp hstester-client.cpp main.cpp)
qt4_automoc(${hstester-client_SRCS})
add_executable(hstest-client ${hstester-client_SRCS})
target_link_libraries(hstest-client ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTNETWORK_LIBRARY})
