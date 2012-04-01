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
    all.tag annotation.tag any.tag anyAttribute.tag
    appInfo.tag attribute.tag attributeGroup.tag
    choice.tag complexContent.tag complexType.tag
    description.rc documentation.tag element.tag
    enumeration.tag extension.tag field.tag
    fractionDigits.tag group.tag import.tag
    include.tag key.tag keyref.tag length.tag
    list.tag maxInclusive.tag maxLength.tag
    minInclusive.tag minLength.tag notation.tag
    pattern.tag redefine.tag restriction.tag
    schema.tag selector.tag sequence.tag
    simpleContent.tag simpleType.tag totalDigits.tag
    union.tag unique.tag whiteSpace.tag
    minExclusive.tag maxExclusive.tag
  DESTINATION ${DATA_INSTALL_DIR}/quanta/dtep/xml-schema )
