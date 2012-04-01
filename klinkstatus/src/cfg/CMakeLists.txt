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

include_directories(
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES klinkstatus.kcfg DESTINATION ${KCFG_INSTALL_DIR} )


##### cfg (static) ##############################

kde_add_library( cfg STATIC_PIC
  SOURCES klsconfig.kcfgc
)
