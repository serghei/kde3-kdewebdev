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
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
  ${CMAKE_CURRENT_SOURCE_DIR}/../factory
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kommanderwidget.h kommander_export.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kommanderwidget (shared) ##################

kde_add_library( kommanderwidget SHARED AUTOMOC
  SOURCES
    expression.cpp function.cpp functionlib.cpp invokeclass.cpp
    kmdrmainwindow.cpp kommanderfunctions.cpp kommanderwidget.cpp
    kommanderwindow.cpp myprocess.cpp parsenode.cpp parser.cpp
    parserdata.cpp
  VERSION 0.0.0
  LINK
    kommanderfactory_pic-static kommanderplugin-shared kio-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
