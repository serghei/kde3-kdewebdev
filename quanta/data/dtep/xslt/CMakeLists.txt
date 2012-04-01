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
    apply-imports.tag attribute-set.tag attribute.tag
    call-template.tag choose.tag comment.tag
    copy-of.tag decimal-format.tag description.rc
    element.tag fallback.tag for-each.tag
    if.tag import.tag key.tag message.tag
    namespace-alias.tag number.tag otherwise.tag
    output.tag param.tag preserve-space.tag
    processing-instruction.tag sort.tag
    strip-space.tag stylesheet.tag template.tag
    text.tag transform.tag value-of.tag variable.tag
    when.tag with-param.tag
  DESTINATION ${DATA_INSTALL_DIR}/quanta/dtep/xslt )
