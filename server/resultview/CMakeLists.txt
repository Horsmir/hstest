cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstest-result_SRCS dlgselect.cpp ${share_SRC_STUD} resultview.cpp main.cpp)
set(hstest-result_UICS select.ui result_view.ui)

qt4_automoc(${hstest-result_SRCS})
QT4_WRAP_UI(UI_RESULT_HEADERS ${hstest-result_UICS})

add_executable(hstest-result WIN32 ${hstest-result_SRCS} ${UI_RESULT_HEADERS} ${QRC_SERVER_SOURCE})
target_link_libraries(hstest-result ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS hstest-result DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES hstest-result.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
