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

add_subdirectory( cfg )
add_subdirectory( utils )
add_subdirectory( parser )
add_subdirectory( engine )
add_subdirectory( ui )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/ui/settings
  ${CMAKE_CURRENT_BINARY_DIR}/ui
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES klinkstatus_part.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES klinkstatus_shell.rc DESTINATION ${DATA_INSTALL_DIR}/klinkstatus )
install( FILES klinkstatus_part.rc DESTINATION ${DATA_INSTALL_DIR}/klinkstatuspart )
install( FILES klinkstatus.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )


##### libklinkstatuspart (module) ###############

kde_add_kpart( libklinkstatuspart AUTOMOC
  SOURCES klinkstatus_part.cpp global.cpp actionmanager.cpp
  LINK
    ui-static settings-static cfg-static utils-static engine-static parser_klinkstatus-static
    khtml-shared ${LIBXML_LIBRARIES} ${LIBXSLT_LIBRARIES}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### klinkstatus (executable) ##################

kde_add_executable( klinkstatus AUTOMOC
  SOURCES klinkstatus.cpp main.cpp
  LINK kparts-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
