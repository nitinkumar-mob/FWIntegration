
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_INPUT_PARAMS_H
#define _swarmin_INPUT_PARAMS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstring>
//#include <Python.h>

#define SWARMIN_INPUT_PARAMS_PATH_ARG "-param_file_path"
#define SWARMIN_INPUT_PARAMS_FILE_NAME "swarmin_input_params"
#define SWARMIN_INPUT_PARAMS_NODE_ID_ARG "-node_id"


#define DATA_FILE_EXT_CSV "csv"
#define DATA_FILE_EXT_PNG "png"

#define ML_ENGINE_TF "tf"
#define ML_ENGINE_PT "PT"

#define CONTROLLER_VERSION_CPLUSPLUS "cpp"
#define CONTROLLER_VERSION_PYTHON "py"


/********************************************************************/
/***** Params file parameters *****/

#define SWARMIN_ROOT_DIR_NAME "SWARMIN_ROOT_DIR_NAME"
// Optional parameter; root directory for storing model data
// Usage: SWARMIN_ROOT_DIR_NAME <full path>
// Default = "."

#define SWARMIN_EWI_FULL_FILE_NAME "SWARMIN_EWI_FULL_FILE_NAME"
// Optional parameter;File for error, warning and info output
// Usage: SWARMIN_EWI_FULL_FILE_NAME <full path file name>
// Default = if not specified, stderr

#define SWARMIN_DEBUG_FULL_FILE_NAME "SWARMIN_DEBUG_FULL_FILE_NAME"
// Optional parameter; File for debug output
// Usage: SWARMIN_DEBUG_FULL_FILE_NAME <full path file name>
// Default = if not specified, stderr

#define SWARMIN_NUM_CPUS "SWARMIN_NUM_CPUS"
// Optional parameter; Number of CPUs available for multithreading
// Usage: SWARMIN_NUM_CPUS <int - number of cpus>
// Default = if not specified, 1

#define SWARMIN_NUM_THREADS_PER_CPU "SWARMIN_NUM_THREADS_PER_CPU"
// Optional parameter; Number of threads to create per CPU
// Usage: SWARMIN_NUM_THREADS_PER_CPU <int - number of threads per cpu>
// Default = if not specified, 16

#define SWARMIN_PYTHON_FILE_NAME "SWARMIN_PYTHON_FILE_NAME"
// Compulsory parameter; name of python file for ML processing
// Usage: SWARMIN_PYTHON_FILE_NAME <name without path or .pyc extension or quotes>
// Default = none

#define SWARMIN_PYTHON_FUNCTION_NAME "SWARMIN_PYTHON_FUNCTION_NAME"
// Compulsory parameter; name of python function for ML processing
// Usage: SWARMIN_PYTHON_FUNCTION_NAME <name without quotes>
// Default = none

#define SWARMIN_DATA_FILE_EXT "SWARMIN_DATA_FILE_EXT"
// Compulsory parameter; the file extension of the input data packets
// Usage: SWARMIN_DATA_FILE_EXT <csv or png without quotes>
// Default = none

#define SWARMIN_SEND_MODEL_TO_CONTROLLER_URL "SWARMIN_SEND_MODEL_TO_CONTROLLER_URL"
// Compulsory parameter; Controller end point to which edge nodes should send models for verification
// Usage: SWARMIN_SEND_MODEL_TO_CONTROLLER_URL <URL without quotes>
// Default = none

#define SWARMIN_POLL_MODEL_PROCESSED_MESSAGE_URL "SWARMIN_POLL_MODEL_PROCESSED_MESSAGE_URL"
// Compulsory parameter;
// Controller end point where an edge node should poll if a model sent by it has been verified
// Usage: SWARMIN_POLL_MODEL_PROCESSED_MESSAGE_URL <URL without quotes>
// Default = none

#define SWARMIN_POLL_LATEST_VERIFIED_MODEL_URL "SWARMIN_POLL_LATEST_VERIFIED_MODEL_URL"
// Compulsory parameter;
// Controller end point where an edge node should keep polling for the latest verified model across the network
// Usage: SWARMIN_POLL_LATEST_VERIFIED_MODEL_URL <URL without quotes>
// Default = none

#define SWARMIN_REGISTER_MODEL_NODE_URL "SWARMIN_REGISTER_MODEL_NODE_URL"
// Compulsory parameter;
// Controller end point where an edge node should register itself as part of its initial setup
// Usage: SWARMIN_REGISTER_MODEL_NODE_URL <URL without quotes>
// Default = none

#define SWARMIN_ML_ENGINE "SWARMIN_ML_ENGINE"
// Compulsory parameter;
// TensorFlow or PyTorch
// Usage: SWARMIN_ML_ENGINE <tf or pt without quotes>
// Default = none

#define SWARMIN_CONTROLLER_VERSION "SWARMIN_CONTROLLER_VERSION"
// Optional parameter; which version of controller - C++ or Python; should eventually go away
// Usage: SWARMIN_CONTROLLER_VERSION cpp or py without quotes
// Default = py


class cSwarminInputParams
{
    public:
        cSwarminInputParams(int argc, char* argv[]);
        ~cSwarminInputParams();
        bool readParamsFile();
        bool closeOpenFileHandles();
        inline FILE* getEWIOutputFile() {return(ewiOutputFile);}
        inline FILE* getDebugOutputFile() {return(debugOutputFile);}
        inline int getNumCPUs() {return(numCPUs);}
        inline int getNumThreadsPerCPU() {return(numThreadsPerCPU);}
        char* getRootDirPath();
    void setRootDirPath(const char* rootPath);
        char* getPythonFileName();
        char* getPythonFunctionName();
        char* getDataFileExt();
        char* getSendModelToControllerURL();
        char* getPollModelProcessedMessageURL();
        char* getPollLatestVerifiedModelURL();
        char* getRegisterModelNodeURL();
        char* getMLEngine();
        char* getControllerVersion();
	int getNodeID();

    private:
        char* inputParamsFilePath;    
        char* rootDirPath;    
        FILE* ewiOutputFile;
        FILE* debugOutputFile;
        int numCPUs;
        int numThreadsPerCPU;
        char* pythonFileName;    
        char* pythonFunctionName;    
        char* dataFileExt;    
        char* sendModelToControllerURL;    
        char* pollModelProcessedMessageURL;
	char* pollLatestVerifiedModelURL;
	char* registerModelNodeURL;
        char* mlEngine;
	char* controllerVersion;
	int nodeID;
};

extern cSwarminInputParams* theInputParams;

#endif
