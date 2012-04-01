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
  ${CMAKE_CURRENT_SOURCE_DIR}/../widget
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kommanderplugin.h specials.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kommanderplugin (shared) ##################

kde_add_library( kommanderplugin SHARED AUTOMOC
  SOURCES kommanderplugin.cpp specialinformation.cpp
  VERSION 0.0.0
  LINK kdeui-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
