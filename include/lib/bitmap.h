#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    size_t size;  // Number of bits
    unsigned char *bits;
} Bitmap;


Bitmap *bitmap_create(uint32_t width, uint32_t height);
void bitmap_destroy(Bitmap *bitmap);

#endif