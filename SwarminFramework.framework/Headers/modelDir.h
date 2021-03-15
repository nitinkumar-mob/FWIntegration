
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_MODELDIR_H
#define _swarmin_MODELDIR_H

//#include <Python.h>

#include "list.h"
#include "rwLock.h"

class cModelDir
{
    public:
        cModelDir(char* rootDirName, char* thisDirName);
        ~cModelDir();
	char* getDirName();
	cRWLock* getDirLock();
	bool setModelVersion(int parentNodeID, int versionNumber);
	bool setModelVersion(char* aModelVersion);
	char* getModelVersion();
	bool setBaseModelVersion(char* aModelVersion);
	char* getBaseModelVersion();
    private:
	char* dirName;
	cRWLock* dirLock;
	char modelVersion[256];
	char baseModelVersion[256];
};

#endif
