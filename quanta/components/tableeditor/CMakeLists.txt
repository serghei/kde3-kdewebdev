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
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/dialogs/tagdialogs
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### tableeditor (static) ######################

kde_add_library( tableeditor STATIC_PIC AUTOMOC
  SOURCES tableeditors.ui tableeditor.cpp tableitem.cpp
)
