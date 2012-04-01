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

add_subdirectory( data )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### csseditor (static) ########################

kde_add_library( csseditor STATIC_PIC AUTOMOC
  SOURCES
    fontfamilychoosers.ui cssselectors.ui
    csseditors.ui fontfamilychooser.cpp
    cssselector.cpp csseditor.cpp specialsb.cpp
    doubleeditors.cpp qmyhighlighter.cpp
    colorrequester.cpp propertysetter.cpp
    shorthandformer.cpp colorslider.cpp
    csseditor_globals.cpp tlpeditors.cpp
    styleeditor.cpp stylesheetparser.cpp
    cssshpropertyparser.cpp percentageeditor.cpp
)
