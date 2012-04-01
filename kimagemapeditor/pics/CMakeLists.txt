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

kde_install_icons( kimagemapeditor )
kde_install_icons( addpoint arrow circle circle2 freehand lower polygon raise rectangle removepoint DESTINATION ${DATA_INSTALL_DIR}/kimagemapeditor/icons )
install( FILES addpointcursor.png freehandcursor.png polygoncursor.png removepointcursor.png DESTINATION ${DATA_INSTALL_DIR}/kimagemapeditor )
