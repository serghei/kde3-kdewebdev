#################################################
#
#  (C) 2010 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include( FindPkgConfig )


# find kdelibs
# FIXME should be more flexibile
set( CMAKE_MODULE_PATH "${CMAKE_INSTALL_PREFIX}/share/cmake" )
if( NOT EXISTS "${CMAKE_MODULE_PATH}/FindKDE3.cmake" )
  message( FATAL_ERROR
      "\n"
      "####################################################################\n "
      "${CMAKE_MODULE_PATH}/FindKDE3.cmake does not exists.\n "
      "Please pass corect CMAKE_INSTALL_PREFIX to cmake.\n"
      "####################################################################\n" )
endif( )
include( FindKDE3 )


# libxml-2.0
if( BUILD_QUANTA OR BUILD_KLINKSTATUS OR BUILD_KXSLDBG )
  pkg_search_module( LIBXML libxml-2.0 )
  if( LIBXML_FOUND )
    if( ${LIBXML_VERSION} VERSION_LESS "2.6" )
      tde_message_fatal( "libxml-2.0 version must be at least 2.6" )
    endif( )
  else( )
    tde_message_fatal( "libxml-2.0 are required, but not found on your system" )
  endif( )
endif( )


# libxslt
if( BUILD_QUANTA OR BUILD_KLINKSTATUS OR BUILD_KXSLDBG )
  pkg_search_module( LIBXSLT libxslt )
  if( NOT LIBXSLT_FOUND )
    tde_message_fatal( "libxslt are required, but not found on your system" )
  endif( )
endif( )
