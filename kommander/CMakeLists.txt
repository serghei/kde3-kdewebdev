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

add_definitions( -DKOMMANDER -DDESIGNER -DHAVE_KDE )

add_subdirectory( icons )
add_subdirectory( plugin )
add_subdirectory( factory )
add_subdirectory( widget )
add_subdirectory( widgets )
add_subdirectory( pluginmanager )
add_subdirectory( editor )
add_subdirectory( executor )
add_subdirectory( part )
add_subdirectory( working )
add_subdirectory( examples )
add_subdirectory( kmdrtools )


install( FILES x-kommander.desktop DESTINATION ${MIME_INSTALL_DIR}/application )
