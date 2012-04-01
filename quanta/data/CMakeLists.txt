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

add_subdirectory( doc )
add_subdirectory( dtep )
add_subdirectory( icons )
add_subdirectory( pics )
add_subdirectory( templates )
add_subdirectory( toolbars )
add_subdirectory( config )

install( FILES chars tips DESTINATION ${DATA_INSTALL_DIR}/quanta )
