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

add_subdirectory( toolbar )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

kde_install_icons( )
install( FILES kfilereplacepart.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES kfilereplacepartui.rc DESTINATION ${DATA_INSTALL_DIR}/kfilereplacepart )
install( FILES kfilereplaceui.rc DESTINATION ${DATA_INSTALL_DIR}/kfilereplace )
install( FILES kfilereplace.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )


##### libkfilereplacepart (module) ##############

kde_add_kpart( libkfilereplacepart AUTOMOC
  SOURCES
    kfilereplacepart.cpp kfilereplaceview.cpp kfilereplaceviewwdg.ui
    kaddstringdlg.cpp kaddstringdlgs.ui knewprojectdlg.cpp
    knewprojectdlgs.ui koptionsdlg.cpp koptionsdlgs.ui
    kfilereplacelib.cpp report.cpp commandengine.cpp
    configurationclasses.cpp
  LINK kparts-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kfilereplace (executable) #################

kde_add_executable( kfilereplace AUTOMOC
  SOURCES kfilereplace.cpp main.cpp
  LINK kparts-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
