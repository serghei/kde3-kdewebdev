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
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/dialogs/tagdialogs
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/messages
  ${CMAKE_SOURCE_DIR}/quanta/parts/kafka
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### utility (static) ##########################

kde_add_library( utility STATIC_PIC AUTOMOC
  SOURCES
    quantacommon.cpp tagaction.cpp
    toolbartabwidget.cpp toolbarxmlgui.cpp
    newstuff.cpp quantanetaccess.cpp qpevents.cpp
    quantabookmarks.cpp tagactionmanager.cpp
    tagactionset.cpp
)
