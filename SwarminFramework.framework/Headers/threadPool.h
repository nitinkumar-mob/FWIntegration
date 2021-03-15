
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_THREAD_POOL_H
#define _swarmin_THREAD_POOL_H

#include <pthread.h>
#include <list.h>

#define NUM_CPUS 1
#define NUM_THREADS_PER_CPU 16

enum threadTaskPriority { THREAD_TASK_PRIORITY_HIGH,
                          THREAD_TASK_PRIORITY_MEDIUM,
                          THREAD_TASK_PRIORITY_LOW
                        };

class cThreadTask
{
    public:
        cThreadTask(void (*theFunction)(void*), void* theData);
//      inline void*() getFunctionToCall() {return(functionToCall);}
//      inline void* getFunctionData() {return(functionData);}

//  private:
        void (*functionToCall)(void*);
        void* functionData;
};

void* checkForWork(void* dummy);

class cThreadPool
{
    public:
        cThreadPool();
        ~cThreadPool();
        bool initializeThreadPool(int numCPUs, int numThreadsPerCPU);
        bool addThreadTask(void(* theFunction)(void*), void* theData, 
                  threadTaskPriority taskPriority = THREAD_TASK_PRIORITY_HIGH);
        void threadCheckForWork();
        bool tasksPending();

    private:
        int numThreads;
        pthread_t** threadPoolList;  
        cPtrList* pendingHighPriorityTasks;   
        cPtrList* pendingMediumPriorityTasks;   
        cPtrList* pendingLowPriorityTasks;   
        pthread_mutex_t* taskQueueMutex;
        pthread_cond_t* taskQueueNotEmpty;
        bool shutdown;
};

extern cThreadPool* theThreadPool;

#endif
