#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <unistd.h>
#include <fcntl.h>
#include "md5.h"

#define BUFFER_SIZE 4096

void calculate_file_md5(int fd, unsigned char *result) {
    MD5_CTX md5_ctx;
    MD5_Init(&md5_ctx);

    unsigned char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        MD5_Update(&md5_ctx, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        return;
    }

    MD5_Final(result, &md5_ctx);
}

void calculate_buffer_md5(unsigned char *buffer, size_t length, unsigned char *result) {
    MD5_CTX md5_ctx;
    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, buffer, length);
    MD5_Final(result, &md5_ctx);
}

void print_md5(unsigned char *md5) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        printf("%02x", md5[i]);
    }
    printf("\n");
}



