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
  ${CMAKE_BINARY_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/quanta/src
  ${CMAKE_SOURCE_DIR}/quanta/parsers
  ${CMAKE_SOURCE_DIR}/quanta/utility
  ${CMAKE_SOURCE_DIR}/quanta/treeviews
  ${CMAKE_SOURCE_DIR}/quanta/dialogs
  ${CMAKE_SOURCE_DIR}/quanta/dialogs/tagdialogs
  ${CMAKE_SOURCE_DIR}/quanta/components/debugger
  ${CMAKE_SOURCE_DIR}/quanta/components/debugger/interfaces
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### project (static) ##########################

kde_add_library( project STATIC_PIC AUTOMOC
  SOURCES
    projectoptions.ui projectnewgenerals.ui
    projectnewgeneral.cpp projectnewlocals.ui
    projectnewlocal.cpp rescanprj.cpp rescanprjdir.ui
    projectnewfinals.ui projectuploads.ui
    projectnewfinal.cpp projectupload.cpp
    project.cpp projectnewwebs.ui projectnewweb.cpp
    uploadprofiledlgs.ui projectlist.cpp
    membereditdlgs.ui teammembersdlgs.ui
    teammembersdlg.cpp membereditdlg.cpp
    subprojecteditdlgs.ui eventconfigurationdlgs.ui
    eventeditordlgs.ui eventconfigurationdlg.cpp
    eventeditordlg.cpp uploadprofiles.cpp
    uploadprofilespage.ui projectprivate.cpp
  DEPENDENCIES dialogs-static
)
