
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/


#ifndef _swarmin_CONTROL_NODE_H
#define _swarmin_CONTROL_NODE_H

#include <modelNetwork.h>

void globalQueueModelforVerif(void* aControlDataTupleVoidPtr);
void globalCreateCheckModelSentToControllerThread(void* aControllerNodeVoidPtr);
void globalCreateCheckForRegisterModelNodeThread(void* aControllerNodeVoidPtr);

class cControllerNode: public cModelNode
{
    public:
        cControllerNode(int aNodeID, char* aRootDir);
        ~cControllerNode();
	
	int registerModelNode(cModelNode* aModelNode);
	
	bool respondRequestSendModelToController(cSavedModelVersion* aModelVersion);
	
        bool createCheckModelSentToControllerThread();
	bool createCheckModelSentToControllerLoop();
	bool pollForModelSentToController();
	bool unpackModelSentToController(char* aSavedModelFileNameInclMetadata);

	bool queueModelforVerification(int sendingNodeID, cSavedModelVersion* aModelVersion);
	bool testModelVersion(cSavedModelVersion* aModelVersion); // Test a received version to see if it should become official version
        bool broadcastLatestVerifiedVersion();

	// Postponed
	bool respondRequestCancelModelSentToController(cModelNode* sendingNode, cSavedModelVersion* aModelVersion);

	bool setIncomingModelsDirName(char* aDirName);
	char* getIncomingModelsDirName();
	bool setIncomingModelsDirCounter(int anInt);
	int getIncomingModelsDirCounter();
	bool incrementIncomingModelsDirCounter();
	bool loadModelSentToController(char* anIncomingModelDir);
	cModelNode* getModelNodeByID(int aNodeID);
	bool writeModelProcessedMessage(int sendingNodeID, char* verifiedModelVersion, bool status);
	bool writeLatestVerifiedModel(int receivingingNodeID, cSavedModelVersion* aModelVersion);
	bool setKeepCheckingForModelSentToController(bool aBoolVal);
	bool getKeepCheckingForModelSentToController();
	bool stopAllWaitLoops();
	bool setKeepCheckingForRegisterModelNode(bool aBoolVal);
	bool getKeepCheckingForRegisterModelNode();
	bool createCheckForRegisterModelNodeThread();
	bool createCheckForRegisterModelNodeLoop();
	bool pollForModelNodeSentForReg();
	
    private:
	int numNodes;
	cModelNode* nodeArray[MAX_NUM_NODES];
	char incomingModelsDirName[256];
	int incomingModelsDirCounter;
	bool keepCheckingForModelSentToController;
	cSavedModelVersion* lastBroadcastVersion;
	bool keepCheckingForRegisterModelNode;
};

class cControlDataTuple
{
    public:
        cControlDataTuple(int aNodeID, cSavedModelVersion* aVersion);
        int aModelNodeID;
	cSavedModelVersion* aModelVersion;
};

extern cControllerNode* theControllerNode;
//extern PyObject* pythonFunctionToCall;
	  
#endif
