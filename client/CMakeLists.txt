project(hstest-client)
cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${share_SRC_DIR})

set(hstester-client_SRCS dlgeditfonts.cpp dlgregister.cpp reportview.cpp report.cpp testthread.cpp ${share_SRC} testmanager.cpp dlgconfig.cpp hstester-client.cpp main.cpp)
set(hstester-client_UIS reportview.ui dlgregister.ui dlgeditfonts.ui dlgconfig.ui mainwindow.ui)
set(hstester-client_QRCS hstest-client.qrc)

qt4_automoc(${hstester-client_SRCS})
QT4_WRAP_UI(UI_HEADERS ${hstester-client_UIS})
QT4_ADD_RESOURCES(QRC_SOURCES ${hstester-client_QRCS})

add_executable(hstest-client WIN32 ${hstester-client_SRCS} ${UI_HEADERS} ${QRC_SOURCES})
target_link_libraries(hstest-client ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTNETWORK_LIBRARY})

install(TARGETS hstest-client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(DIRECTORY ../images DESTINATION ${CMAKE_INSTALL_PREFIX}/share/hstest)
install(FILES hstest-client.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
install(FILES ../icons/hstest.svg DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
install(FILES ../docs/hstest-client-help_ru.pdf DESTINATION ${CMAKE_INSTALL_PREFIX}/share/doc/hstest)
