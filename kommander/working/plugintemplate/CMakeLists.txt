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

set( templateName kommanderplugin )


##### install template ##########################

install( FILES
    ${templateName}.kdevtemplate
  DESTINATION ${DATA_INSTALL_DIR}/kdevappwizard/templates )

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${templateName}.tar.gz ${templateName}.png
  DESTINATION ${DATA_INSTALL_DIR}/kdevappwizard )


##### generate template archive #################

set( templateFiles src-Makefile.am plugin.cpp widget.h widget.cpp app.kdevelop )

add_custom_command(
  OUTPUT ${templateName}.tar.gz
  COMMAND tar zcf ${templateName}.tar.gz -C ${CMAKE_CURRENT_SOURCE_DIR} ${templateFiles}
  DEPENDS ${templateFiles} )

add_custom_target( ${templateName}.tar.gz-template ALL DEPENDS ${templateName}.tar.gz )
