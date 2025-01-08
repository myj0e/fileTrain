#ifndef MD5_H
#define MD5_H


void calculate_file_md5(int fd, unsigned char *result);
void print_md5(unsigned char *md5);


#endif