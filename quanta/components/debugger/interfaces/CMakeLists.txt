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
  ${CMAKE_SOURCE_DIR}/quanta/components/debugger
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)

install( FILES quantadebugger.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )


##### debuggerinterface (static) ################

kde_add_library( debuggerinterface STATIC_PIC AUTOMOC
  SOURCES debuggerinterface.cpp debuggerclient.cpp
)
