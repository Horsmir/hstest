project(hstester-server)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstester-server_SRCS ${share_SRC_STUD} logfileout.cpp ${share_SRC} testmanager.cpp testthread.cpp testserver.cpp hstester-server.cpp main.cpp)
set(hstester-server_QRCS server.qrc)

qt4_automoc(${hstester-server_SRCS})
QT4_ADD_RESOURCES(QRC_SERVER_SOURCES ${hstester-server_QRCS})

add_executable(hstest-server ${hstester-server_SRCS})
target_link_libraries(hstest-server ${QT_QTCORE_LIBRARY} ${QT_QTNETWORK_LIBRARY})

if(NOT localstatedir)
	set(localstatedir ${CMAKE_INSTALL_PREFIX}/../var)
endif(NOT localstatedir)

add_subdirectory(utils utils)

install(TARGETS hstest-server DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

add_subdirectory(resultview)
