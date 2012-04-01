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
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/parts/kafka
  ${CMAKE_SOURCE_DIR}/quanta/components/csseditor
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### tagdialogs (static) #######################

kde_add_library( tagdialogs STATIC_PIC AUTOMOC
  SOURCES
    tagmisc.ui listdlg.cpp tagmaildlg.cpp
    tagquicklistdlg.cpp tagquicklistdlgdata.cpp
    tagdialog.cpp tagattr.cpp pictureview.cpp
    tagimgdlg.cpp tagxml.cpp tagwidget.cpp
    colorcombo.cpp tagimgdlgdata.cpp tagmiscdlg.cpp
    tagmail.ui
)
