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

add_subdirectory( scripts )
add_subdirectory( others )
add_subdirectory( html )

install( FILES dirinfo
  RENAME .dirinfo
  DESTINATION ${DATA_INSTALL_DIR}/quanta/templates/text )
