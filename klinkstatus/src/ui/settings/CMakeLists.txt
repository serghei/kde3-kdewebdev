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
  ${CMAKE_CURRENT_BINARY_DIR}/..
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### settings (static) #########################

kde_add_library( settings STATIC_PIC AUTOMOC
  SOURCES
    configsearchdialog.ui configresultsdialog.ui
    configidentificationdialog.cpp configidentificationdialogui.ui
  DEPENDENCIES cfg-static
)
