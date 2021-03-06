
/***************************************************************************
                          param_cmds.c  - libxslt parameter commands for xsldbg
                             -------------------
    begin                : Wed Nov 21 2001
    copyright            : (C) 2001 by Keith Isdale
    email                : k_isdale@tpg.com.au
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "xsldbg.h"
#include "debugXSL.h"
#include "options.h"

#include "xsldbgmsg.h"
#include "xsldbgthread.h"       /* for get thread status */


/* -----------------------------------------

   libxslt parameter related commands

  ------------------------------------------- */

/** 
 * xslDbgShellAddParam:
 * @arg: A string comprised of two words separated by
 *          one or more spaces which are in UTF-8 
 *
 * Add a libxslt parameter to be sent to libxslt later on
 *
 * Returns 1 on success,
 *         0 otherwise
*/
int
xslDbgShellAddParam(xmlChar * arg)
{
    int result = 0;
    parameterItemPtr paramItem = NULL;
    static const char *errorPrompt = I18N_NOOP("Failed to add parameter");
    xmlChar *opts[2];

    if (!arg) {
        xsldbgGenericErrorFunc(i18n("Error: Invalid arguments for the command %1.\n").arg("addparam"));
    }else{
	if ((xmlStrLen(arg) > 1) && splitString(arg, 2, opts) == 2) {
	    int count;
	    for (count = 0; count < arrayListCount(optionsGetParamItemList()); count++){
		paramItem = (parameterItemPtr)arrayListGet(optionsGetParamItemList(), count);
		if (paramItem != NULL){
		    if (xmlStrCmp(opts[0], paramItem->name) == 0){
			/* parameter exist just update its value */
			if (paramItem->value)
			    xmlFree(paramItem->value);
			paramItem->value = xmlStrdup(opts[1]); 
			return 1;
		    }
		}
	    }
	    paramItem = optionsParamItemNew(opts[0], opts[1]);
	    result = arrayListAdd(optionsGetParamItemList(), paramItem);
	} else {
	    xsldbgGenericErrorFunc(i18n("Error: Invalid arguments for the command %1.\n").arg("addparam"));
	}
    }
    if (!result)
        xsldbgGenericErrorFunc(QString("Error: %1\n").arg(i18n(errorPrompt)));
    else {
	xsldbgGenericErrorFunc("\n");
    }
    return result;
}


/**
 * xslDbgShellDelParam:
 * @arg: A single white space trimmed parameter number to look for
 * 
 * Delet a libxslt parameter to be sent to libxslt later on
 *
 * Returns 1 if able to delete parameter @name,
 *         0 otherwise
 */
int
xslDbgShellDelParam(xmlChar * arg)
{
    int result = 0;
    static const char *errorPrompt = I18N_NOOP("Failed to delete parameter");
    long paramId;
    xmlChar *opts[2];

    if (!arg) {
	xsldbgGenericErrorFunc(i18n("Error: Invalid arguments for the command %1.\n").arg("delparam"));
    }else{
	if (xmlStrLen(arg) > 0) {
	    if (splitString(arg, 1, opts) == 1) {
		if ((xmlStrlen(opts[0]) == 0) ||
			!sscanf((char *) opts[0], "%ld", &paramId)) {
		    xsldbgGenericErrorFunc(i18n("Error: Unable to parse %1 as a line number.\n").arg(xsldbgText(opts[0])));
		} else {
		    result =
			arrayListDelete(optionsGetParamItemList(), paramId);
		    if (!result)
			xsldbgGenericErrorFunc(i18n("Error: Unable to find parameter %1.\n").arg(paramId));
		}
	    } else {
		xsldbgGenericErrorFunc(i18n("Error: Invalid arguments for the command %1.\n").arg("delparam"));
	    }
	} else {
	    /* Delete all parameters */
	    arrayListEmpty(optionsGetParamItemList());
	    result = 1;
	}
    }
    if (!result)
        xsldbgGenericErrorFunc(QString("Error: %1\n").arg(i18n(errorPrompt)));
    else
         xsldbgGenericErrorFunc("\n");

    return result;
}


/**
 * xslDbgShellShowParam:
 * @arg: Not used
 *
 * Print list of current paramters
 *
 * Returns 1 on success,
 *         0 otherwise
 */
int
xslDbgShellShowParam(xmlChar * arg)
{
    Q_UNUSED(arg);
    int result = 0;
    static const char *errorPrompt = I18N_NOOP("Unable to print parameters");

    if (getThreadStatus() == XSLDBG_MSG_THREAD_RUN) {
        int paramIndex = 0;
        int itemCount = arrayListCount(optionsGetParamItemList());

        notifyListStart(XSLDBG_MSG_PARAMETER_CHANGED);

        if (itemCount > 0) {
            parameterItemPtr paramItem = NULL;

            while (paramIndex < itemCount) {
                paramItem = (parameterItemPtr)
                    arrayListGet(optionsGetParamItemList(), paramIndex++);
                if (paramItem != NULL)
                    notifyListQueue(paramItem);
            }
        }
        notifyListSend();
        result = 1;
    } else {

        if (optionsPrintParamList())
            result = 1;
        else
        xsldbgGenericErrorFunc(QString("Error: %1\n").arg(i18n(errorPrompt)));
        xsldbgGenericErrorFunc("\n");
    }
    return result;
}
