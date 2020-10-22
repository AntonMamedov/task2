#pragma once
#include <stdlib.h>

#define DEFAULT_ALLOC_SIZE 32

typedef struct{
    void** array;
    size_t size;
    size_t alloc_size;
}Vector;

void vec_init(Vector* vec);
int vec_push(void* elem, Vector* vec);
void* vec_get(size_t index, Vector* vec);
void vec_release(void (*releaser)(void* elem), Vector* vec);