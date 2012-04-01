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


##### parser_klinkstatus (static) ###############

# NOTE: this parser is suffixed with "_klinkstatus" because we
#       have already a target named "parser" inside quanta

kde_add_library( parser_klinkstatus STATIC_PIC
  SOURCES htmlparser.cpp http.cpp mstring.cpp node.cpp url.cpp
)
