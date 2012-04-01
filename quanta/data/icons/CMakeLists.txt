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

add_subdirectory( 22x22 )
add_subdirectory( 16x16 )

kde_install_icons( quanta )
install( FILES files.png DESTINATION ${DATA_INSTALL_DIR}/quanta/toolbar )
