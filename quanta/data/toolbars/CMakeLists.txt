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

add_subdirectory( html )
add_subdirectory( xml )
add_subdirectory( wml-1-2 )
add_subdirectory( tagxml )
add_subdirectory( schema )
add_subdirectory( cfml )
add_subdirectory( kde-docbook )
add_subdirectory( docbook )
add_subdirectory( css )

install( FILES
    debug.toolbar.tgz
  DESTINATION ${DATA_INSTALL_DIR}/quanta/toolbars )
