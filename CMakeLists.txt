project(hstest)
cmake_minimum_required(VERSION 2.6)

if(CMAKE_CROSSCOMPILING)
  set(QT_HEADERS_DIR "/usr/i486-mingw32/include")
  set(QT_LIBRARY_DIR "/usr/i486-mingw32/lib")
endif(CMAKE_CROSSCOMPILING)

if (NOT CMAKE_BUILD_TYPE)
    set ( CMAKE_BUILD_TYPE Release )
endif (NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES [Dd]ebug)
    message(STATUS "Debug build")
    add_definitions(-DDEBUG)
else()
    message(STATUS "non-debug build")
    add_definitions(-DNDEBUG)
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

if (NOT CMAKE_INSTALL_PREFIX)
	set(CMAKE_INSTALL_PREFIX /usr)
endif(NOT CMAKE_INSTALL_PREFIX)
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

set(APP_NAME "Hs Test")

set(MAJOR_VERSION 0)
set(MINOR_VERSION 5)
set(PATCH_VERSION 2)
set(HSTEST_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})
add_definitions(-DHSTEST_VERSION=\"${HSTEST_VERSION}\")
message(STATUS "")
message(STATUS "${APP_NAME} version: ${HSTEST_VERSION}")
message(STATUS "")

find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

configure_file (
  "${PROJECT_SOURCE_DIR}/hstestconfigure.h.in"
  "${PROJECT_BINARY_DIR}/hstestconfigure.h"
  )

set(share_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/share-src/)
include_directories(${share_SRC_DIR})

set(share_SRC ${share_SRC_DIR}/testnode.cpp ${share_SRC_DIR}/test.cpp ${share_SRC_DIR}/testcategories.cpp ${share_SRC_DIR}/testdb.cpp)
set(share_SRC_STUD ${share_SRC_DIR}/student.cpp ${share_SRC_DIR}/studentdb.cpp)

add_subdirectory(server)
add_subdirectory(client)
#add_subdirectory(share-src)

########## Add make dist target ################
set(CPACK_PACKAGE_VERSION "${HSTEST_VERSION}")
set(CPACK_SOURCE_GENERATOR "TBZ2")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "hstest-${HSTEST_VERSION}")
set(CPACK_IGNORE_FILES "/CVS/;/\\\\.git\;/\\\\.svn/;\\\\.swp$;\\\\.#;/#;\\\\.tar.gz$;/CMakeFiles/;CMakeCache.txt;build/;dist/;exp/;.*~;*.kdev4;installer-win32/;exp-win32/;server/data/;build-win32/;data/")
set(CPACK_SOURCE_IGNORE_FILES ${CPACK_IGNORE_FILES})
include(CPack)
# simulate autotools' "make dist"
add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)
