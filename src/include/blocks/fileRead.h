#ifndef FILEREADE_H
#define FILEREADE_H
#include "fileInfo.h"


FilesizeResult readFromFile(int fd, void *buffer, off_t offset, size_t length);

#endif