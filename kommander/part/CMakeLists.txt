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
  ${CMAKE_CURRENT_SOURCE_DIR}/../executor
  ${CMAKE_CURRENT_SOURCE_DIR}/../factory
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kommander_part.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### libkommander_part (module) ################

kde_add_kpart( libkommander_part AUTOMOC
  SOURCES kommander_part.cpp
  LINK instance_pic-static kommanderwidget-shared kparts-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
