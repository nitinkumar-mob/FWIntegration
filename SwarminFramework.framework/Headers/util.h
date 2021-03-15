
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_UTIL_H
#define _swarmin_UTIL_H

#include <string>
#include "archive.h"
#include "archive_entry.h"

enum ewiLevel {ERROR = 1, WARNING, INFO, NONE}; // Error, Warning, Info level

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void ewiPrintf(ewiLevel msgLevel, const char* fmt, ...);
void debugPrintf(const char* fmt, ...);
void ewiColorPrintf(const char* colorCode, ewiLevel msgLevel, const char* fmt, ...);
int getFileSize(const char* aFileName);

class cUtil
{
    public:
        bool mkDirPath(const char* aDirPath, mode_t mode);
        std::string base_name(std::string const & path);
    bool copyFiletoFile(const char* srcFile, const char* destFile);
        bool copyFile(const char* srcFile, const char* destDir);
        bool rmFilePath(const char* filePath);
        void rmDirPath(const char* dirPath, bool rmRootDir);        
        void mvFile(const char* srcFile, const char* destDir);     
        void write_archive(const char *outname, const char * path);
        int extract_archive(const char *filename, const char *outDir);


        
	int mkDirIfDirDoesNotExist(char* aDirName, mode_t mode);
    void add_file_to_tar(struct archive_entry *entry, const char *filename, 
                         const char *relFilename, struct stat st, 
                         struct archive *a, char *buff);
    void add_dir_to_tar(const char * path, struct archive_entry *entry, 
                        struct stat st, struct archive *a, char *buff, 
                        const char* folder_path);  
    int copy_data(struct archive *ar, struct archive *aw);

};

extern cUtil* theUtilObj;


#endif
