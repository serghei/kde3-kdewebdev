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
  ${CMAKE_SOURCE_DIR}/quanta/components/debugger/interfaces
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)

link_directories(
  ${TQT_LIBRARY_DIRS}
)


##### other data ################################

install( FILES quantadebuggerdbgp.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### quantadebuggerdbgp (module) ###############

kde_add_kpart( quantadebuggerdbgp AUTOMOC
  SOURCES
    quantadebuggerdbgp.cpp dbgpsettingss.ui
    dbgpsettings.cpp dbgpnetwork.cpp
    qbytearrayfifo.cpp
  LINK debuggerinterface-static kio-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
