#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "fileInfo.h"

/**
 * @brief 从文件中读取数据
 *
 * 通过文件描述符从指定偏移量读取指定长度的数据到缓冲区。
 *
 * @param fd 文件描述符
 * @param buffer 指向存储读取数据的缓冲区
 * @param offset 文件中开始读取的位置
 * @param length 要读取的字节数
 * @return FilesizeResult 返回操作结果的状态码，可能的值包括：
 *         - FD_INVALID: 文件描述符无效
 *         - LSEEK_FAILED: lseek系统调用失败
 *         - READ_FAILED: read系统调用失败
 *         - SUCCESS: 操作成功
 */
FilesizeResult readFromFile(int fd, void *buffer, off_t offset, size_t length) {
    if (fd == -1) {
        return FD_INVALID;
    }

    // 移动文件指针到指定位置
    if (lseek(fd, offset, SEEK_SET) == -1) {
        return LSEEK_FAILED;
    }

    // 读取数据到缓冲区
    ssize_t bytesRead = read(fd, buffer, length);
    if (bytesRead == -1) {
        return READ_FAILED;
    } else if ((size_t)bytesRead < length) {
        printf("Warning: Read fewer bytes than requested (%zd/%zu).\n", bytesRead, length);
    }

    return SUCCESS;
}
FilesizeResult readFromFile(int fd, void *buffer, off_t offset, size_t length) {
    if (fd == -1) {
        return FD_INVALID;
    }

    // 移动文件指针到指定位置
    if (lseek(fd, offset, SEEK_SET) == -1) {
        return LSEEK_FAILED;
    }

    // 读取数据到缓冲区
    ssize_t bytesRead = read(fd, buffer, length);
    if (bytesRead == -1) {
        return READ_FAILED;
    } else if ((size_t)bytesRead < length) {
        printf("Warning: Read fewer bytes than requested (%zd/%zu).\n", bytesRead, length);
    }

    return SUCCESS;
}