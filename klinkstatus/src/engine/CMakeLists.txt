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
)


##### engine (static) ###########################

kde_add_library( engine STATIC_PIC AUTOMOC
  SOURCES linkchecker.cpp linkstatus.cpp searchmanager.cpp linkfilter.cpp
)
