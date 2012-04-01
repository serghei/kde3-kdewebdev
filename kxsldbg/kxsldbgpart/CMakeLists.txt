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

add_subdirectory( libqtnotfier )
add_subdirectory( libxsldbg )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### other data ################################

kde_install_icons( )
install( FILES kxsldbg_part.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES kxsldbg_part.rc DESTINATION ${DATA_INSTALL_DIR}/kxsldbgpart )


##### sources ####################################

set( kxsldbgcommon_SRCS
  xsldbgwalkspeedimpl.cpp xsldbgtemplatesimpl.cpp
  xsldbgtemplatelistitem.cpp xsldbgsourcesimpl.cpp xsldbgoutputview.cpp
  xsldbglocalvariablesimpl.cpp xsldbglocallistitem.cpp
  xsldbglistitem.cpp xsldbginspector.cpp xsldbgglobalvariablesimpl.cpp
  xsldbggloballistitem.cpp xsldbgentitiesimpl.cpp xsldbgdoc.cpp
  xsldbgdialogbase.cpp xsldbgdebugger.cpp xsldbgconfigimpl.cpp
  xsldbgcallstackimpl.cpp xsldbgbreakpointsimpl.cpp
  xsldbgbreakpointlistitem.cpp qxsldbgdoc.cpp kxsldbg_part.cpp
  kxsldbg_partif.skel xsldbgwalkspeed.ui xsldbgtemplates.ui
  xsldbgsources.ui xsldbgmsgdialog.ui xsldbglocalvariables.ui
  xsldbgglobalvariables.ui xsldbgentities.ui xsldbgconfig.ui
  xsldbgcallstack.ui xsldbgbreakpoints.ui
)


##### libkxsldbgpart (module) ###################

kde_add_kpart( libkxsldbgpart AUTOMOC
  SOURCES ${kxsldbgcommon_SRCS}
  LINK
    qtnotfier-static xsldbg-static katepartinterfaces-shared
    ${LIBXML_LIBRARIES} ${LIBXSLT_LIBRARIES} ${EXSLT_LIBRARY} ${PTHREAD_LIBRARY} ${READLINE_LIBRARY}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kxsldbgcommon (static) ####################
##### needed by kxsldbg, as non-pic

kde_add_library( kxsldbgcommon STATIC AUTOMOC
  SOURCES ${kxsldbgcommon_SRCS}
)
