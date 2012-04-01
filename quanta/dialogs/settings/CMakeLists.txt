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
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### settingsdialogs (static) ##################

kde_add_library( settingsdialogs STATIC_PIC AUTOMOC
  SOURCES
    parseroptionsui.ui parseroptions.cpp
    previewoptionss.ui previewoptions.cpp
    filemaskss.ui filemasks.cpp styleoptionss.ui
    abbreviations.ui abbreviation.cpp
    codetemplatedlgs.ui
)
