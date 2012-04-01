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

install( FILES
    plugins.rc actions.rc quantaui.rc
  DESTINATION ${DATA_INSTALL_DIR}/quanta )

install( FILES
    quanta_preview_config.desktop
  DESTINATION ${SERVICES_INSTALL_DIR} )
