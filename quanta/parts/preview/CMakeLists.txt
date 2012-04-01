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
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### preview (static) ##########################

kde_add_library( preview STATIC_PIC AUTOMOC
  SOURCES whtmlpart.cpp
)
