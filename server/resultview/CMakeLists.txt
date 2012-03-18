cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstest-result_SRCS dlgselect.cpp ${share_SRC_STUD} resultview.cpp main.cpp)
qt4_automoc(${hstest-result_SRCS})
add_executable(hstest-result ${hstest-result_SRCS})
target_link_libraries(hstest-result ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS hstest-result DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES hstest-result.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
