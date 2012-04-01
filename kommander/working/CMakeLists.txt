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

add_subdirectory( plugintemplate )

install( PROGRAMS
    extractkmdr kmdr2po DESTINATION
  ${DATA_INSTALL_DIR}/kommander/translating )
