project(hstestcfg)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstestcfg_SRCS dlgeditmarks.cpp dlgeditgroups.cpp ${share_SRC_STUD} dlgedittest.cpp ${share_SRC} testmanager.cpp hstestcfg.cpp dlgaddtest.cpp dlgdeletetest.cpp main.cpp)
qt4_automoc(${hstestcfg_SRCS})
add_executable(hstestcfg ${hstestcfg_SRCS})
target_link_libraries(hstestcfg ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS hstestcfg DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES hstestcfg.svg DESTINATION ${CMAKE_INSTALL_PREFIX}/share/hstest/icons)
install(FILES hstestcfg.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
install(FILES hstestcfg.svg DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
