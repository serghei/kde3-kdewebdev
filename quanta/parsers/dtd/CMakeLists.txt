#################################################
#
#  (C) 2010-2011 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/dialogs
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### dtdparser (static) ########################

kde_add_library( dtdparser STATIC_PIC
  SOURCES
    dtepcreationdlg.ui dtdparser.cpp
  DEPENDENCIES dialogs-static
)
