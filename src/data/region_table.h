#ifndef __REGION_TABLE_H__
#define __REGION_TABLE_H__

#include <stdlib.h>
#include <stdio.h>

#define MAX_REGION_COUNT 50

typedef struct Region {
    int size;
    int nis;
    // TODO: ast tree
} Region;

Region construct_region(int size, int nis);

void init_region_table();

void insert_region(int nis);

#endif // __REGION_TABLE_H__
