#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "fileManage.h"


/**
 * @brief 获取文件大小
 *
 * 通过文件描述符获取文件的大小，并将结果存储在传入的指针参数中。
 *
 * @param fd 文件描述符
 * @param filesize 指向存储文件大小的off_t类型指针
 * @return FilesizeResult 返回操作结果的状态码，可能的值包括：
 *         - FD_INVALID: 文件描述符无效
 *         - FSTAT_FAILED: fstat系统调用失败
 *         - SUCCESS: 操作成功
 */
FilesizeResult getFilesize(int fd, off_t *filesize) {
    if (fd == -1) {
        return FD_INVALID;
    }

    struct stat fileStat;
    if (fstat(fd, &fileStat) != 0) {
        return FSTAT_FAILED;
    }
    *filesize = fileStat.st_size;
    return SUCCESS;
}


/**
 * @brief 检查文件大小操作的结果
 *
 * 根据传入的FilesizeResult枚举值，打印相应的操作结果信息。
 *
 * @param result 文件大小操作的结果，类型为FilesizeResult枚举
 */
void checkFilesizeResult(FilesizeResult result) {
    switch (result) {
        case SUCCESS:
            printf("Success: File size retrieved successfully.\n");
            break;
        case FD_INVALID:
            printf("Error: Invalid file descriptor provided.\n");
            break;
        case FSTAT_FAILED:
            perror("Error: fstat failed");
            break;
        case MEMORY_ALLOC_FAILED:
            printf("Error: Memory allocation failed.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }
}


