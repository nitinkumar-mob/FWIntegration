
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_MODELNETWORK_H
#define _swarmin_MODELNETWORK_H

//#include <Python.h>

#include "list.h"
#include "rwLock.h"
#include "modelConstants.h"
#include "savedModelVersion.h"
#include "featureDataPacket.h"
#include "modelDir.h"
#include "cgiCurlIntfc.h"


void globalQueueLatestVerifiedModel(void* aModelDataTupleVoidPtr);
void globalQueuePollModelProcessedMessage(void* aModelDataTupleVoidPtr);
void globalCreateCheckForNewDataPacketThread(void* aModelNodeVoidPtr);
void globalCreateCheckLatestVerifiedModelThread(void* aModelNodeVoidPtr);

class cModelNode
{
    public:
        cModelNode(int aNodeID, char* aRootDir, bool isControllerNode);
        ~cModelNode();
	void setNodeID(int aNodeID);
	int getNodeID();

        bool createCheckLatestVerifiedModelThread();
	bool createCheckLatestVerifiedModelLoop();
	bool unpackTarFileInclMeta(char* tarFileDirFullName, char* tarFileFullName);
	bool loadModelSentToNode(char* anIncomingModelDir);
        bool queueLatestVerifiedModel(cSavedModelVersion* aModelVersion); // Queue latest version from controller node 
        bool receiveLatestVerifiedModel(cSavedModelVersion* aModelVersion); // Process latest version from controller node 

	bool unpackSavedModelVersion(cSavedModelVersion* aModelVersion, cModelDir* targetDir);
	bool receiveNewDataPacket(cFeatureDataPacket* aFeatureDataPacket); // New data packet for training and / or prediction
	bool makePrediction(cFeatureDataPacket* aFeatureDataPacket); // Use model to predict given an input
	bool unpackSavedModelAndUpdateTraining(cSavedModelVersion* aModelVersion = NULL); // Train and update your own model version using all unverified pending packets
	bool requestSendModelToController(); // Share updated model with the network

	bool queuePollModelProcessedMessage(cSavedModelVersion* aModelVersion);
	bool pollModelProcessedMessage(cSavedModelVersion* aModelVersion);
	bool receiveModelProcessedMessage(char* processedModelVersion, bool processingSuccessful); // Controller has processed this model version

	cSavedModelVersion* packageModelForSending(cModelDir* aModelDir, bool includeMetadata);			
	bool packageTFModelForSending(cModelDir* aModelDir, char* tempDir);			
	bool packagePTModelForSending(cModelDir* aModelDir, char* tempDir);			

	// Postponed
        bool requestCancelModelSentToController(cSavedModelVersion* aModelVersion);
	
	cModelDir* getLatestVerifiedVersionDir();
	cModelDir* getMyModelVersionDir();
	bool runMLInPython(cFeatureDataPacket* aDataFile, mlMode trainOrPredictMode);
	bool setHaveVerifiedModel(bool aBoolVal);
	bool checkHaveVerifiedModel();
	char* generateTarFileName(char* modelVersionStr);
	char* generateTarFileNameInclMetadata(char* modelVersionStr);
	cRWLock* getPythonCodeLock();
	bool deleteDataPackets(cPtrNode* lastProcessedDataPacket);
	bool setKeepCheckingForLatestVerifiedModel(bool aBoolVal);
	bool getKeepCheckingForLatestVerifiedModel();
	bool setMyCgiCurlIntfc(cCgiCurlIntfc* aCgiCurlIntfc);
	cCgiCurlIntfc* getMyCgiCurlIntfc();
	bool stopAllWaitLoops();
	bool deleteModelDir(cSavedModelVersion* aModelVersion);
	char* getRootDir();
        bool setKeepCheckingForNewDataPacket(bool aBoolVal);
        bool getKeepCheckingForNewDataPacket();
        bool createCheckForNewDataPacketThread();
	bool createCheckForNewDataPacketLoop();
	bool pollNewDataPacket(cFeatureDataPacket** aDataPacketPtr);
	bool exitModelNode();	
	bool setDeleteDataAfterProcessing(bool aBoolVal);
	bool getDeleteDataAfterProcessing();
    char* getNewDataPacketDir(){return newDataPacketDir;};
	
    private:
        int nodeID;
	char* rootDir;
	cModelDir* latestVerifiedVersionDir;
	cModelDir* myModelVersionDir; // Includes latest learning, may not be verified
	bool haveVerifiedModel;
	cSavedModelVersion* lastModelSentToController;
	cDataPacketList* myDataPackets;
	int myModelVersionNumber;
	bool keepCheckingForNewDataPacket;
	bool keepCheckingForLatestVerifiedModel;
	cCgiCurlIntfc* myCgiCurlIntfc;
	char* newDataPacketDir;
	bool deleteDataAfterProcessing;
};

class cModelDataTuple
{
    public:
        cModelDataTuple(cModelNode* aNode, cSavedModelVersion* aVersion);
        cModelNode* aModelNode;
	cSavedModelVersion* aModelVersion;
};


//extern PyObject* pythonFunctionToCall;
extern cRWLock* pythonCodeLock;

#endif
