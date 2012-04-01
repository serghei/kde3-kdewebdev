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

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../factory
  ${CMAKE_CURRENT_SOURCE_DIR}/../widget
  ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### kmdr-plugins (executable) #################

kde_add_executable( kmdr-plugins AUTOMOC
  SOURCES main.cpp mainwindow.cpp pluginmanager.cpp
  LINK kommanderfactory_nopic-static kio-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
