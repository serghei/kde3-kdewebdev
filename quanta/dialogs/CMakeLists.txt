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

add_subdirectory( settings )
add_subdirectory( tagdialogs )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### dialogs (static) ##########################

kde_add_library( dialogs STATIC_PIC AUTOMOC
  SOURCES
    copyto.cpp dirtydialog.ui dirtydlg.cpp
    donationdialog.ui dtdselectdialog.ui
    fourbuttonmessagebox.ui casewidget.ui
    actionconfigdialogs.ui actionconfigdialog.cpp
    filecombo.cpp specialchardialogs.ui
    specialchardialog.cpp dtepeditdlgs.ui
    dtepstructureeditdlgs.ui dtepeditdlg.cpp
    loadentitydlgs.ui
)
