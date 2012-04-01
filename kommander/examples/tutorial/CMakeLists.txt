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

install( PROGRAMS
    append.kmdr calc.kmdr dcop.kmdr globals.kmdr loop.kmdr
    progressbar.kmdr slots.kmdr strings.kmdr tree.kmdr arrays.kmdr
    cmdline.kmdr dialogs.kmdr initialize.kmdr picview.kmdr settings.kmdr
    statusbar.kmdr table.kmdr widgets.kmdr
  DESTINATION ${DATA_INSTALL_DIR}/kmdr-editor/editor/tutorial )

install( FILES
    README
  DESTINATION ${DATA_INSTALL_DIR}/kmdr-editor/editor/tutorial )
