
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_RW_LOCK_H
#define _swarmin_RW_LOCK_H

#include <pthread.h>

class cRWLock
{
    public:
        cRWLock();
        ~cRWLock();
        bool readerLock(); 
        bool readerUnlock(); 
        bool writerLock(); 
        bool writerUnlock(); 

    private:
        int numReadersReading;
        int numWritersWriting;
        pthread_mutex_t* rwLockMutex;
        pthread_cond_t* rwLockFree;
};

#endif
