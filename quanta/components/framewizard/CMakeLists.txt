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
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/components/framewizard
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### framewizard (static) ######################

kde_add_library( framewizard STATIC_PIC AUTOMOC
  SOURCES
    fmfpeditors.ui fmrceditors.ui framewizards.ui
    fwglobal.cpp areaattributedb.cpp
    selectablearea.cpp treenode.cpp
    visualframeeditor.cpp fmfpeditor.cpp
    fmrceditor.cpp framewizard.cpp
)
