project(hstestcfg)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstestcfg_SRCS dlgaddbintest.cpp dlgeditmarks.cpp dlgeditgroups.cpp ${share_SRC_STUD} dlgedittest.cpp ${share_SRC} testmanager.cpp hstestcfg.cpp dlgaddtest.cpp dlgdeletetest.cpp main.cpp)
set(hstestcfg_UICS main_dialog.ui dlgedittest.ui dlgeditmarks.ui dlgeditgroups.ui dlgdeletetest.ui dlgaddtest.ui dlgaddbintest.ui)

qt4_automoc(${hstestcfg_SRCS})
QT4_WRAP_UI(UI_CFG_HEADERS ${hstestcfg_UICS})

add_executable(hstestcfg WIN32 ${hstestcfg_SRCS} ${UI_CFG_HEADERS} ${QRC_SERVER_SOURCE})
target_link_libraries(hstestcfg ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS hstestcfg DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES ../../icons/hstestcfg.png DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
install(FILES hstestcfg.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
