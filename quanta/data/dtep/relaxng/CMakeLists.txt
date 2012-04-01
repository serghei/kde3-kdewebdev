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
    anyName.tag attribute.tag choice.tag data.tag
    define.tag description.rc div.tag element.tag
    empty.tag except.tag externalRef.tag grammar.tag
    group.tag include.tag interleave.tag list.tag
    mixed.tag name.tag notAllowed.tag nsName.tag
    oneOrMore.tag optional.tag param.tag
    parentRef.tag ref.tag start.tag text.tag
    value.tag zeroOrMore.tag
  DESTINATION ${DATA_INSTALL_DIR}/quanta/dtep/relaxng )
