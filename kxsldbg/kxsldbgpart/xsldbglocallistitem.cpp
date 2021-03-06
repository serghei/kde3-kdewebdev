/*************************************************************************** 
                          xsldbglocallistitem.cpp  -  description 
                             ------------------- 
    begin                : Sun Jan 13 2002 
    copyright            : (C) 2002 by Keith Isdale 
    email                  : k_isdale@tpg.com.au 
 ***************************************************************************/ 
 
/*********************************************************************************** 
 *                                                                         										* 
 *   This program is free software; you can redistribute it and/or modify       * 
 *   it under the terms of the GNU General Public License as published by  * 
 *   the Free Software Foundation; either version 2 of the License, or         * 
 *   (at your option) any later version.                                   							* 
 *                                                                         										* 
 ************************************************************************************/ 
 
#include "xsldbglocallistitem.h" 
#include <klocale.h>
 
XsldbgLocalListItem::XsldbgLocalListItem(QListView *parent, QString fileName, int lineNumber, 
	QString localName, QString templateContext, QString selectXPath, bool localVariable) 
: XsldbgListItem(parent, 3, fileName, lineNumber)									 
{ 
    varName = localName; 
    contextName = templateContext;	 
    XPath = selectXPath;	 

    setText(0, localName); 
    setText(1, templateContext);
    if (localVariable)
	setText(2, i18n("Local"));
    else
	setText(2, i18n("Global"));
} 

XsldbgLocalListItem::~XsldbgLocalListItem() 
{ 
} 

QString XsldbgLocalListItem::getVarName() 
{ 
    return varName; 
} 

QString XsldbgLocalListItem::getContextName() 
{ 
    return contextName; 
} 

QString XsldbgLocalListItem::getXPath() 
{ 
    return XPath; 
} 

bool XsldbgLocalListItem::isLocalVariable() 
{ 
    return localVar; 
} 
