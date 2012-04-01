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

add_subdirectory( interfaces )
add_subdirectory( gubed )
add_subdirectory( dbgp )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/interfaces
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/messages
  ${CMAKE_SOURCE_DIR}/quanta/parts/preview
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### debuggermanager (static) ##################

kde_add_library( debuggermanager STATIC_PIC AUTOMOC
  SOURCES
    debuggermanager.cpp debuggerbreakpoint.cpp
    quantadebuggerinterface.cpp debuggervariable.cpp
    debuggerui.cpp variableslistview.cpp
    debuggerbreakpointlist.cpp
    debuggervariablesets.ui
    debuggerbreakpointview.cpp
    pathmapper.cpp pathmapperdialogs.ui
    pathmapperdialog.cpp pathmapperdialog.h
    conditionalbreakpointdialogs.ui
    conditionalbreakpointdialog.cpp
    conditionalbreakpointdialog.h
    backtracelistview.cpp
  LINK debuggerinterface-static
)
