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
  ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
  ${CMAKE_CURRENT_SOURCE_DIR}/../factory
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### kommanderwidgets (shared) #################

kde_add_library( kommanderwidgets SHARED AUTOMOC
  SOURCES
    aboutdialog.cpp buttongroup.cpp checkbox.cpp closebutton.cpp
    combobox.cpp datepicker.cpp dialog.cpp execbutton.cpp
    fileselector.cpp fontdialog.cpp groupbox.cpp konsole.cpp label.cpp
    lineedit.cpp listbox.cpp pixmaplabel.cpp plugin.cpp popupmenu.cpp
    progressbar.cpp radiobutton.cpp richtexteditor.cpp scriptobject.cpp
    slider.cpp spinboxint.cpp statusbar.cpp subdialog.cpp table.cpp
    tabwidget.cpp textbrowser.cpp textedit.cpp timer.cpp toolbox.cpp
    treewidget.cpp wizard.cpp
  VERSION 0.0.0
  LINK kommanderwidget-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
