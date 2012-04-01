#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

add_subdirectory( pics )

add_definitions( -DVERSION="1.0.1" )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kimagemapeditorpart.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES kimagemapeditorui.rc kimagemapeditorpartui.rc DESTINATION ${DATA_INSTALL_DIR}/kimagemapeditor )
install( FILES kimagemapeditor.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )


##### common sources ############################

set( common_SRCS
  qextfileinfo.cpp areacreator.cpp kimearea.cpp kimecommands.cpp
  kimedialogs.cpp kimagemapeditor.cpp drawzone.cpp arealistview.cpp
  imageslistview.cpp mapslistview.cpp
)


##### libkimagemapeditor (module) ###############

kde_add_kpart( libkimagemapeditor AUTOMOC
  SOURCES ${common_SRCS}
  LINK khtml-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimagemapeditor (executable) ##############

kde_add_executable( kimagemapeditor AUTOMOC
  SOURCES ${common_SRCS} main.cpp kimeshell.cpp
  LINK khtml-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
