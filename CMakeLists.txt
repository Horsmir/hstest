project(hstest)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(share_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/share-src/)
include_directories(${share_SRC_DIR})

set(share_SRC ${share_SRC_DIR}/testnode.cpp ${share_SRC_DIR}/test.cpp ${share_SRC_DIR}/testcategories.cpp ${share_SRC_DIR}/testdb.cpp)

add_subdirectory(server)
add_subdirectory(client)
#add_subdirectory(share-src)