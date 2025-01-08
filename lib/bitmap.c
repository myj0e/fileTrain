#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

/**
 * @brief 创建位图
 *
 * 创建一个包含指定数量位的位图，并初始化所有位为0。
 *
 * @param num_bits 位图中位的数量
 * @return Bitmap* 指向新创建的位图结构的指针，如果内存分配失败则返回NULL
 */
Bitmap* create_bitmap(size_t num_bits) {
    Bitmap *bitmap = (Bitmap*)malloc(sizeof(Bitmap));
    if (!bitmap) return NULL;

    bitmap->size = num_bits;
    bitmap->bits = (unsigned char*)calloc((num_bits + 7) / 8, sizeof(unsigned char));
    if (!bitmap->bits) {
        free(bitmap);
        return NULL;
    }

    return bitmap;
}

// Destroy the bitmap and free its memory
void destroy_bitmap(Bitmap *bitmap) {
    if (bitmap) {
        free(bitmap->bits);
        free(bitmap);
    }
}

// Set a bit at position 'index' to 1
void set_bit(Bitmap *bitmap, size_t index) {
    if (index >= bitmap->size) return;
    bitmap->bits[index / 8] |= 1 << (index % 8);
}

// Clear a bit at position 'index' to 0
void clear_bit(Bitmap *bitmap, size_t index) {
    if (index >= bitmap->size) return;
    bitmap->bits[index / 8] &= ~(1 << (index % 8));
}

// Get the value of a bit at position 'index'
int get_bit(const Bitmap *bitmap, size_t index) {
    if (index >= bitmap->size) return -1;
    return (bitmap->bits[index / 8] & (1 << (index % 8))) != 0;
}

// Print the entire bitmap for debugging purposes
void print_bitmap(const Bitmap *bitmap) {
    for (size_t i = 0; i < bitmap->size; ++i) {
        printf("%d", get_bit(bitmap, i));
    }
    printf("\n");
}

int main() {
    Bitmap *bitmap = create_bitmap(32);
    if (!bitmap) {
        fprintf(stderr, "Failed to create bitmap\n");
        return 1;
    }

    set_bit(bitmap, 0);
    set_bit(bitmap, 5);
    set_bit(bitmap, 31);

    print_bitmap(bitmap);  // Output: 10000010000000000000000000000001

    clear_bit(bitmap, 5);
    print_bitmap(bitmap);  // Output: 10000000000000000000000000000001

    int bit_value = get_bit(bitmap, 31);
    printf("Bit at index 31 is %d\n", bit_value);  // Output: Bit at index 31 is 1

    destroy_bitmap(bitmap);
    return 0;
}



