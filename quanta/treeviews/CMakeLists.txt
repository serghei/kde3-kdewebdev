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
  ${CMAKE_BINARY_DIR}/quanta/dialogs/tagdialogs
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/quanta/dialogs/tagdialogs
  ${CMAKE_SOURCE_DIR}/quanta/messages
  ${CMAKE_SOURCE_DIR}/quanta/parts/kafka
  ${CMAKE_SOURCE_DIR}/quanta/components/csseditor
  ${CMAKE_SOURCE_DIR}/quanta/plugins
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### treeviews (static) ########################

kde_add_library( treeviews STATIC_PIC AUTOMOC
  SOURCES
    uploadtreeview.cpp uploadtreefolder.cpp
    uploadtreefile.cpp fileinfodlg.ui
    quantapropertiespage.ui newtemplatedirdlg.cpp
    templatedirform.ui templatestreeview.cpp
    projecttreeview.cpp structtreeview.cpp
    doctreeview.cpp docitem.cpp docfolder.cpp
    structtreetag.cpp filestreeview.cpp
    tagattributetree.cpp tagattributeitems.cpp
    scripttreeview.cpp basetreeview.cpp
    servertreeview.cpp
  DEPENDENCIES dialogs-static
)
