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

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/quanta/dialogs
  ${CMAKE_BINARY_DIR}/quanta/dialogs/settings
  ${CMAKE_BINARY_DIR}/quanta/dialogs/tagdialogs
  ${CMAKE_BINARY_DIR}/quanta/parts/kafka
  ${CMAKE_BINARY_DIR}/quanta/components/tableeditor
  ${CMAKE_BINARY_DIR}/quanta/components/csseditor
  ${CMAKE_BINARY_DIR}/quanta/components/framewizard
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/project
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/parsers/dtd
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/parts/kafka
  ${CMAKE_SOURCE_DIR}/quanta/parts/preview
  ${CMAKE_SOURCE_DIR}/quanta/components/debugger
  ${CMAKE_SOURCE_DIR}/quanta/components/tableeditor
  ${CMAKE_SOURCE_DIR}/quanta/components/csseditor
  ${CMAKE_SOURCE_DIR}/quanta/components/framewizard
  ${CMAKE_SOURCE_DIR}/quanta/messages
  ${CMAKE_SOURCE_DIR}/quanta/treeviews
  ${CMAKE_SOURCE_DIR}/quanta/plugins
  ${CMAKE_SOURCE_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/quanta/dialogs/settings
  ${CMAKE_SOURCE_DIR}/quanta/dialogs/tagdialogs
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)

link_directories(
  ${TQT_LIBRARY_DIRS}
)


##### other data ################################

install( FILES quanta.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES x-webprj.desktop DESTINATION ${MIME_INSTALL_DIR}/application )


##### quanta (executable) #######################

set_source_files_properties( kqapp.cpp PROPERTIES COMPILE_FLAGS -DPREFIX=\\"${CMAKE_INSTALL_PREFIX}\\" )

kde_add_executable( quanta AUTOMOC
  SOURCES
    quanta_init.cpp quantaview.cpp quantadoc.cpp
    main.cpp document.cpp kqapp.cpp quanta.cpp
    dcopwindowmanagerif.skel dcopsettingsif.skel
    dcopquantaif.skel dcopsettings.cpp dtds.cpp
    dcopquanta.cpp viewmanager.cpp
  LINK
    project-static plugins-static parser-static
    dtdparser-static treeviews-static dialogs-static
    debuggermanager-static tagdialogs-static
    settingsdialogs-static messages-static
    framewizard-static csseditor-static
    tableeditor-static preview-static
    utility-static quantamodule-static
    kafkalibrary-static kmdi-shared khtml-shared
    knewstuff-shared kabc-shared ktexteditor-shared
    ${LIBXML_LIBRARIES} ${LIBXSLT_LIBRARIES}
  DESTINATION ${BIN_INSTALL_DIR}
)
