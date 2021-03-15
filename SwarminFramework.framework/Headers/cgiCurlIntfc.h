
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_CGICURLINTFC_H
#define _swarmin_CGICURLINTFC_H

#include <stdio.h>
#include <string.h>

#include "curl.h"
#include <savedModelVersion.h>
#include <cgiCurlIntfcConstants.h>

class cCgiCurlIntfc
{
    public:
        cCgiCurlIntfc();
        ~cCgiCurlIntfc();
	bool requestSendModelToController(cSavedModelVersion* aSavedModel);
        bool pollModelProcessedMessage(cSavedModelVersion* aModelVersion,
				       cgiCurlIntfcModelProcessedStatus* processingSuccessfulPtr);
	bool pollLatestVerifiedModel(int modelNodeID, bool* foundVerifiedModel,
				     char foundTarFileDirFullName[], char foundTarFileFullName[],
				     char* latestVerifiedModelVersion);
	bool setIncomingModelsDirCounter(int anInt);
	int getIncomingModelsDirCounter();
	bool incrementIncomingModelsDirCounter();
	bool registerModelNode(void* aModelNode, int* nodeIDPtr);
	
    private:
	int incomingModelsDirCounter;
};

#endif

