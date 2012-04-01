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

include( ConfigureChecks.cmake )

add_subdirectory( kxsldbgpart )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
  ${LIBXML_INCLUDE_DIRS}
)


##### other data ################################

install( FILES kxsldbg_shell.rc DESTINATION ${DATA_INSTALL_DIR}/kxsldbg )
install( FILES kxsldbg.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )


##### kxsldbg (executable) ######################

kde_add_executable( kxsldbg AUTOMOC
  SOURCES kxsldbg.cpp main.cpp kxsldbgif.skel
  LINK kdeui-shared kparts-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### xsldbg (executable) #######################

kde_add_executable( xsldbg AUTOMOC
  SOURCES xsldbgmain.cpp
  LINK xsldbg-static kdeui-shared ${LIBXSLT_LIBRARIES} ${EXSLT_LIBRARY} ${READLINE_LIBRARY}
  DESTINATION ${BIN_INSTALL_DIR}
)
