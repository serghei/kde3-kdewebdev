#################################################
#
#  (C) 2010-2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

cmake_minimum_required( VERSION 2.8 )


##### general package setup #####################

project( kdewebdev )
set( VERSION "3.5.10" )


##### user requested modules ####################

option( BUILD_ALL "Build all" OFF )
option( BUILD_DOC "Build documentation" ${BUILD_ALL} )
option( BUILD_KFILEREPLACE "Build kfilereplace" ${BUILD_ALL} )
option( BUILD_KIMAGEMAPEDITOR "Build kimagemapeditor" ${BUILD_ALL} )
option( BUILD_KLINKSTATUS "Build klinkstatus" ${BUILD_ALL} )
option( BUILD_KOMMANDER "Build kommander" ${BUILD_ALL} )
option( BUILD_KXSLDBG "Build kxsldbg" ${BUILD_ALL} )
option( BUILD_QUANTA "Build quanta" ${BUILD_ALL} )


##### configure checks ##########################

include( ConfigureChecks.cmake )

# enable ascii cast
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -UQT_NO_ASCII_CAST" )


##### source directories ########################

if( BUILD_QUANTA )
  add_subdirectory( lib )
endif( )

kde_conditional_add_subdirectory( BUILD_DOC doc )
kde_conditional_add_subdirectory( BUILD_KFILEREPLACE kfilereplace )
kde_conditional_add_subdirectory( BUILD_KIMAGEMAPEDITOR kimagemapeditor )
kde_conditional_add_subdirectory( BUILD_KLINKSTATUS klinkstatus )
kde_conditional_add_subdirectory( BUILD_KOMMANDER kommander )
kde_conditional_add_subdirectory( BUILD_KXSLDBG kxsldbg )
kde_conditional_add_subdirectory( BUILD_QUANTA quanta )


##### write configure files #####################

configure_file( config.h.cmake config.h @ONLY )
