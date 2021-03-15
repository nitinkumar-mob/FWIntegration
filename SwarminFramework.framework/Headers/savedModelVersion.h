
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_SAVED_MODEL_VERSION_H
#define _swarmin_SAVED_MODEL_VERSION_H

#include "list.h"

// A version of the model for transferring from one node to another
class cSavedModelVersion
{
    public:
        cSavedModelVersion(char* aFileName);
        ~cSavedModelVersion();
	bool setSendingNodeID(int aNodeID);
	int getSendingNodeID();
	bool setModelFullFileName(char* aFileName);
	char* getModelFullFileName();
	bool setModelVersion(char* aModelVersion);
	char* getModelVersion();
	bool setBaseModelVersion(char* aModelVersion);
	char* getBaseModelVersion();
	bool setLastProcessedDataPacket(cPtrNode* aDataPacketNode);
	cPtrNode* getLastProcessedDataPacket();
	bool setModelFullFileNameInclMetadata(char* aFileName);
	char* getModelFullFileNameInclMetadata();

    private:
        char* savedModelFullFileName;
	char modelVersion[256];
	char baseModelVersion[256];
	cPtrNode* lastProcessedDataPacket;
	int sendingNodeID;
        char* savedModelFullFileNameInclMetadata;
};

	  
#endif
