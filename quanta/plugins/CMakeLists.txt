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
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/messages
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### plugins (static) ##########################

kde_add_library( plugins STATIC_PIC AUTOMOC
  SOURCES
    quantaplugininterface.cpp quantaplugineditor.cpp
    quantapluginconfig.cpp quantaplugin.cpp plugineditor.ui
    pluginconfig.ui
)
