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
    abs.tag acos.tag acs.tag array.tag
    asin.tag atn.tag authenticatedcontext.tag
    authenticateduser.tag bitand.tag bitmaskclear.tag
    bitmaskread.tag bitmaskset.tag bitnot.tag
    bitor.tag bitshln.tag bitshrn.tag bitxor.tag
    ceiling.tag chr.tag cjustify.tag compare.tag
    comparenocase.tag cos.tag createobject.tag
    createuuid.tag datetime.tag de.tag
    decimalformat.tag decrementvalue.tag decrypt.tag
    deleteclientvariable.tag description.rc
    directoryexists.tag dollarformat.tag
    duplicate.tag encrypt.tag evaluate.tag
    exp.tag expandpath.tag fileexists.tag find.tag
    fix.tag formatbasen.tag getbasetagdata.tag
    getbasetaglist.tag getbasetemplatepath.tag
    getclientvariableslist.tag
    getcurrenttemplatepath.tag
    getdirectoryfrompath.tag getexception.tag
    getfilefrompath.tag getfunctionlist.tag
    gethttprequestdata.tag gethttptimestring.tag
    getlocale.tag getmetricdata.tag
    getprofilestring.tag gettempdirectory.tag
    gettempfile.tag gettemplatepath.tag
    gettickcount.tag gettoken.tag hash.tag
    htmlcodeformat.tag htmleditformat.tag iif.tag
    incrementvalue.tag inputbasen.tag insert.tag
    int.tag isarray.tag isauthenticated.tag
  DESTINATION ${DATA_INSTALL_DIR}/quanta/dtep/cffunct )
