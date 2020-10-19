#ifndef TF_IDF_METRIC_STR_MAP_H
#define TF_IDF_METRIC_STR_MAP_H

#endif //TF_IDF_METRIC_STR_MAP_H
#include <stdlib.h>

#include "str.h"

typedef struct StrMapNode{
    struct StrMapNode* left;
    struct StrMapNode* right;
    u_int32_t data;
    String key;
}StrMapNode;


u_int32_t* map_update(StrMapNode** root, char* key);
u_int32_t* map_search(StrMapNode** root, char* key);
void    map_post_order(StrMapNode** root, void(*work)(char* key, u_int32_t* data, void* word_data), void* work_data);
void    map_release(StrMapNode** root);