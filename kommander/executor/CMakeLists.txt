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
  ${CMAKE_CURRENT_SOURCE_DIR}/../factory
  ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
  ${CMAKE_CURRENT_SOURCE_DIR}/../widget
  ${CMAKE_CURRENT_SOURCE_DIR}/../widgets
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kmdr-executor.desktop DESTINATION ${APPS_INSTALL_DIR}/.hidden )


##### instance_pic (static) #####################

kde_add_library( instance_pic STATIC_PIC AUTOMOC
  SOURCES instance.cpp dcopkommanderif.skel
)


##### instance_nopic (static) ###################

kde_add_library( instance_nopic STATIC_PIC AUTOMOC
  SOURCES instance.cpp dcopkommanderif.skel
)


##### kmdr-executor (executable) ################

kde_add_executable( kmdr-executor AUTOMOC
  SOURCES main.cpp
  LINK instance_nopic-static kommanderwidgets-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
