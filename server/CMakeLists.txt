project(hstester-server)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstester-server_SRCS logfileout.cpp ${share_SRC} testmanager.cpp testthread.cpp testserver.cpp hstester-server.cpp main.cpp)
qt4_automoc(${hstester-server_SRCS})
add_executable(hstest-server ${hstester-server_SRCS})
target_link_libraries(hstest-server ${QT_QTCORE_LIBRARY} ${QT_QTNETWORK_LIBRARY})

add_subdirectory(utils utils)

install(TARGETS hstest-server DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(DIRECTORY ../icons ../images DESTINATION ${CMAKE_INSTALL_PREFIX}/share/hstest)
install(DIRECTORY data/ DESTINATION ${CMAKE_INSTALL_PREFIX}/var/lib/hstest)