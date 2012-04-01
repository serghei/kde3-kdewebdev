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

add_subdirectory( dtd )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/treeviews
  ${CMAKE_SOURCE_DIR}/quanta/parts/kafka
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### parser (static) ###########################

kde_add_library( parser STATIC_PIC AUTOMOC
  SOURCES
    qtag.cpp node.cpp tag.cpp parser.cpp saparser.cpp
    parsercommon.cpp sagroupparser.cpp
)
