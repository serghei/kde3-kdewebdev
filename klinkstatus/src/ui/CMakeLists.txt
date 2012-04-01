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

add_subdirectory( settings )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/../cfg
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### ui (static) ###############################

kde_add_library( ui STATIC_PIC AUTOMOC
  SOURCES
    sessionwidgetbase.ui sessionwidget.cpp tabwidgetsession.cpp
    klshistorycombo.cpp resultview.cpp treeview.cpp resultssearchbar.cpp
    documentrootdialog.cpp
  DEPENDENCIES cfg-static
)
