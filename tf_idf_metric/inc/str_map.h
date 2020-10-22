#pragma once
#include <stdlib.h>
#include <stdint.h>

#include "str.h"

typedef struct StrMapNode{
    struct StrMapNode* left;
    struct StrMapNode* right;
    u_int32_t data;
    String key;
}StrMapNode;


uint32_t* map_update(StrMapNode** root, char* key);
void    map_post_order(StrMapNode** root, void(*work)(char* key, u_int32_t* data, void* word_data), void* work_data);
void    map_release(StrMapNode** root);