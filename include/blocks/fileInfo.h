#ifndef FILEMANAGE_H
#define FILEMANAGE_H
#include <unistd.h>


// 定义返回值枚举类型
typedef enum {
    SUCCESS,
    FD_INVALID,
    FSTAT_FAILED,
    MEMORY_ALLOC_FAILED,
    LSEEK_FAILED,
    READ_FAILED
} FilesizeResult;


void checkFilesizeResult(FilesizeResult result);
FilesizeResult getFilesize(int fd, off_t *filesize);



#endif