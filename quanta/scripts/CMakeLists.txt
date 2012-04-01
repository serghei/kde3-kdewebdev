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
    scriptinfo.kmdr.info dwt.pl dwt.kmdr.info
    tidy.kmdr.info checkxml.kmdr.info
    meinproc.kmdr.info xmlval.kmdr.info
    xsltproc.kmdr.info htmlquickstart.kmdr.info
    TemplateMagic.pl TemplateMagic.pl.info
    info.css externalpreview.sh info.xsl
    externalpreview.sh.info dwt.pl.info
    gubed_install.kmdr.info
  DESTINATION ${DATA_INSTALL_DIR}/quanta/scripts )

install( PROGRAMS
    scriptinfo.kmdr dwt.kmdr tidy.kmdr checkxml.kmdr
    meinproc.kmdr xmlval.kmdr xsltproc.kmdr
    htmlquickstart.kmdr gubed_install.kmdr
    listwizard.kmdr picturewizard.kmdr
    tablewizard.kmdr docbook_table.kmdr
  DESTINATION ${DATA_INSTALL_DIR}/quanta/scripts )
