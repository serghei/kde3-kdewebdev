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
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### qtnotfier (static) ########################

kde_add_library( qtnotfier STATIC_PIC AUTOMOC
  SOURCES
    xsldbgthread.cpp xsldbgnotifier.cpp xsldbgevent.cpp
    xsldbgdebuggerbase.cpp qtnotifier2.cpp
)
