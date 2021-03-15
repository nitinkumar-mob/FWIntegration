
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_CGICURLINTFCCONSTANTS_H
#define _swarmin_CGICURLINTFCCONSTANTS_H

#define CGICURLINTFC_ROOT_DIR "cgi_curl_intfc_root_dir"
#define CGICURLINTFC_RESPONSE_DATA_DIR "cgicurlintfc_response_data_dir"

#define CGICURLINTFC_MODEL_PROCESSED_MESSAGE_DIR "processed_message_dir"
#define CGICURLINTFC_MODEL_PROCESSED_MESSAGE_FILE "model_processed_status.txt"

#define CGICURLINTFC_LATEST_VERIFIED_MODEL_DIR "latest_verified_model_dir"
#define CGICURLINTFC_INCOMING_MODEL_DIR "incoming_model"
#define CGICURLINTFC_INCOMING_MODEL_TAR_FILE "incoming_model.tar"

#define CGICURLINTFC_REGISTER_MODEL_NODE_DIR "model_reg_dir"
#define CGICURLINTFC_REGISTER_MODEL_NODE_FILE "model_reg_id.txt"

enum cgiCurlIntfcModelProcessedStatus
{
    MODEL_PROCESSED_PASS = 1,
    MODEL_PROCESSED_FAIL = 2,
    MODEL_PROCESSED_NOT_FOUND
};

#endif

