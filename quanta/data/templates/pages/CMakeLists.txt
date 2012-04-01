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

add_subdirectory( php )
add_subdirectory( html )
add_subdirectory( docbook )

install( FILES dirinfo
  RENAME .dirinfo
  DESTINATION ${DATA_INSTALL_DIR}/quanta/templates/pages )
