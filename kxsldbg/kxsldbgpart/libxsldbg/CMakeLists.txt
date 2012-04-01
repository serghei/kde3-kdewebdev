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

add_definitions( -DXSLDBG_BIN="xsldbg" )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### xsldbg (static) ###########################

kde_add_library( xsldbg STATIC_PIC
  SOURCES
    allmoc.cpp xsldbgthread.cpp xsldbg.cpp xsldbgmsg.cpp
    variable_cmds.cpp utils.cpp trace_cmds.cpp template_cmds.cpp
    search_cmds.cpp search.cpp param_cmds.cpp os_cmds.cpp
    options_unix.cpp options.cpp option_cmds.cpp nodeview_cmds.cpp
    help_unix.cpp files_unix.cpp files.cpp file_cmds.cpp debugXSL.cpp
    debug.cpp callstack.cpp breakpoint_cmds.cpp breakpoint.cpp
    arraylist.cpp
)
