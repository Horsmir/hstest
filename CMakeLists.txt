project(hstest)
cmake_minimum_required(VERSION 2.6)

if(CMAKE_CROSSCOMPILING)
  set(QT_HEADERS_DIR "/usr/i486-mingw32/include")
  set(QT_LIBRARY_DIR "/usr/i486-mingw32/lib")
endif(CMAKE_CROSSCOMPILING)

find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(share_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/share-src/)
include_directories(${share_SRC_DIR})

set(share_SRC ${share_SRC_DIR}/testnode.cpp ${share_SRC_DIR}/test.cpp ${share_SRC_DIR}/testcategories.cpp ${share_SRC_DIR}/testdb.cpp)
set(share_SRC_STUD ${share_SRC_DIR}/student.cpp ${share_SRC_DIR}/studentdb.cpp)

add_subdirectory(server)
add_subdirectory(client)
#add_subdirectory(share-src)
