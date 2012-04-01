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

add_definitions( -DQT_NO_SQL )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
  ${CMAKE_CURRENT_SOURCE_DIR}/../widget
  ${CMAKE_BINARY_DIR}
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES kommanderfactory.h DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kommanderfactory_pic (static) #################

kde_add_library( kommanderfactory_pic STATIC_PIC
  SOURCES kommanderfactory.cpp domtool.cpp
)


##### kommanderfactory_nopic (static) #################

kde_add_library( kommanderfactory_nopic STATIC
  SOURCES kommanderfactory.cpp domtool.cpp
)
