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
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### utils (static) ############################

kde_add_library( utils STATIC_PIC AUTOMOC
  SOURCES utils.cpp xsl.cpp
)
