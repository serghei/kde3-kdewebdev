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

add_subdirectory( pics )

add_definitions( -DQT_NO_SQL )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../editor
  ${CMAKE_CURRENT_SOURCE_DIR}/../factory
  ${CMAKE_CURRENT_SOURCE_DIR}/../plugin
  ${CMAKE_CURRENT_SOURCE_DIR}/../widget
  ${CMAKE_CURRENT_SOURCE_DIR}/../widgets
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kommander.xml kommander-new.xml DESTINATION ${DATA_INSTALL_DIR}/katepart/syntax )
install( FILES kmdr-editor.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )


##### kmdr-editor (executable) ##################

kde_add_executable( kmdr-editor AUTOMOC
  SOURCES
    actiondnd.cpp actioneditorimpl.cpp assoctexteditorimpl.cpp
    actionlistview.cpp asciivalidator.cpp assistproc.cpp command.cpp
    connectioneditorimpl.cpp defs.cpp filechooser.cpp formfile.cpp
    formsettingsimpl.cpp formwindow.cpp hierarchyview.cpp
    iconvieweditorimpl.cpp layout.cpp listboxeditorimpl.cpp
    listvieweditorimpl.cpp main.cpp mainwindow.cpp
    mainwindowactions.cpp metadatabase.cpp multilineeditorimpl.cpp
    newformimpl.cpp orderindicator.cpp paletteeditoradvancedimpl.cpp
    paletteeditorimpl.cpp parser.cpp pixmapchooser.cpp previewframe.cpp
    previewwidgetimpl.cpp propertyeditor.cpp qcompletionedit.cpp
    resource.cpp sizehandle.cpp styledbutton.cpp tableeditorimpl.cpp
    widgetdatabase.cpp widgetfactory.cpp wizardeditorimpl.cpp
    workspace.cpp actioneditor.ui assoctexteditor.ui connectioneditor.ui
    createtemplate.ui formsettings.ui iconvieweditor.ui listboxeditor.ui
    listeditor.ui listvieweditor.ui multilineeditor.ui newform.ui
    paletteeditor.ui paletteeditoradvanced.ui pixmapfunction.ui
    preferences.ui previewwidget.ui tableeditor.ui wizardeditor.ui
    choosewidget.ui choosewidgetimpl.cpp functions.ui functionsimpl.cpp
    messagelog.cpp
  LINK kommanderwidgets-shared ktexteditor-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
