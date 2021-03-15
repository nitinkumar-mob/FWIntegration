
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_MODELCONSTANTS_H
#define _swarmin_MODELCONSTANTS_H

#define MAX_NUM_NODES 4294967295 // 2**32 - 1
#define DEFAULT_NODE_ID -1
#define CONTROLLER_NODE_ID 0
#define WORKING_DIR "model_dir"
#define LATEST_VERIFIED_VERSION_DIR "latestVerifiedVersion"
#define MY_MODEL_VERSION_DIR "myModelVersion"
#define TEMP_DIR "tempDir"
#define TAR_FILE_NAME "savedModelVersion"
#define CHECKPOINT_FILE_NAME "checkpoint"
#define METADATA_FILE_NAME "metadata.txt"
#define TAR_FILE_NAME_INCL_METADATA "savedModelVersionInclMetadata"
#define MODEL_CURL_INTFC_MAX_SLEEP_TIME 1024
#define MODEL_CHECK_FOR_NEW_DATA_PACKET_SLEEP_TIME 1
#define MODEL_CHECK_FOR_LATEST_VERIFIED_MODEL_SLEEP_TIME 1

#define MODEL_NEW_DATA_PACKET_DIR "newDataPacketDir"
#define MODEL_FEATURE_COLUMN_NAME "High_Blood_Pres"
#define MODEL_TARGET_COLUMN_NAME "D_Wh_HeartDis"
#define MODEL_COLUMN_SEPERATOR_STR ","

#define MODEL_NODE_EXIT_FILE_NAME "model_node_exit.txt"
#define MODEL_NODE_CHECK_FOR_EXIT_SLEEP_TIME 10

#define PT_FILE_NAME_PREFIX "model_"
#define PT_FILE_NAME_EXT ".pt"

enum mlMode
{
  ML_TRAIN_MODE = 1,
  ML_PREDICT_MODE
};

#endif
