
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_FEATURE_DATA_PACKET_H
#define _swarmin_FEATURE_DATA_PACKET_H

#include "list.h"
#include "rwLock.h"

// An input data packet of features to be used for making a prediction

class cFeatureDataPacket
{
    public:
        cFeatureDataPacket(const char* fileName, const char* sep, const char* featureCol, const char* targetCol);
        ~cFeatureDataPacket();
	char* getDataFileName();
	char* getSeperatorStr();
	char* getFeatureColumnName();
	char* getTargetColumnName();		
    private:
        char* dataFileName;
	char* seperatorStr;
	char* featureColumnName;
	char* targetColumnName;
};

class cDataPacketList
{
    public:
        cDataPacketList();
        ~cDataPacketList();
	cPtrList* getMyDataPacketsList();
	cRWLock* getMyDataPacketsLock();
        bool append(void* anObject);	
        bool readerLock(); 
        bool readerUnlock(); 
        bool writerLock(); 
        bool writerUnlock(); 
    private:
	cPtrList* myDataPacketsList;
	cRWLock* myDataPacketsLock;
};

#endif
