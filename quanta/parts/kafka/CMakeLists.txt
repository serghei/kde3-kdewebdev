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

# FIXME KDE_CXXFLAGS = $(USE_EXCEPTIONS)

add_subdirectory( pics )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/treeviews
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES entities DESTINATION ${DATA_INSTALL_DIR}/kafkapart )


##### kafkalibrary (static) #####################

kde_add_library( kafkalibrary STATIC_PIC AUTOMOC
  SOURCES
    htmlenhancer.cpp domtreeview.cpp kafkacommon.cpp
    kafkahtmlpart.cpp nodeproperties.cpp
    wkafkapart.cpp undoredo.cpp kafkasyncoptionsui.ui
    htmldocumentpropertiesui.ui kafkasyncoptions.cpp
    htmldocumentproperties.cpp cursors.cpp
    kafkadragobject.cpp
  DEPENDENCIES treeviews-static
)
