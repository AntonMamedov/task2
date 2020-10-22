#include "str_map.h"
#include <string.h>

static StrMapNode* map_init(StrMapNode* elem, char* key){
    elem->left = NULL;
    elem->right = NULL;
    str_init(key, &elem->key);
    elem->data = 0;
}

//StrMapNode* map_update(StrMapNode **root, char* key) {
//    if (key == NULL)
//        return NULL;
//    else {
//        if (strcmp(key, "chrysolites") == 0) {
//            int a = 0;
//        }
//        if (*root == NULL) {
//            *root = (StrMapNode *)malloc(sizeof(StrMapNode));
//            *root = map_init(*root, key);
//            StrMapNode *current_elem = *root;
//            return current_elem;
//        } else {
//            StrMapNode *current_elem = *root;
//            int cmp = strcmp(str_get(&current_elem->key), key);
//            if (cmp > 0) {
//                if (current_elem->right == NULL) {
//                    current_elem->right = (StrMapNode*) malloc(sizeof(StrMapNode));
//                    current_elem->right = map_init(current_elem->right, key);
//                    return current_elem;
//                } else
//                    return map_update(&current_elem->right, key);
//            } else if (cmp < 0) {
//                if (current_elem->left == NULL) {
//                    current_elem->left = (StrMapNode *) malloc(sizeof(StrMapNode));
//                    current_elem->left = map_init(current_elem->left, key);
//                    return current_elem;
//                } else {
//                    return map_update(&current_elem->left, key);
//                }
//            } else {
//                return current_elem;
//            }
//        }
//    }
//}

//
uint32_t* map_update(StrMapNode **root, char* key) {
    if (key == NULL)
        return NULL;
    else {
        if (*root == NULL) {
            *root = (StrMapNode *)malloc(sizeof(StrMapNode));
            *root = map_init(*root, key);
            StrMapNode *current_elem = *root;
            return &current_elem->data;
        } else {
            StrMapNode *current_elem = *root;
            int cmp = strcmp(str_get(&current_elem->key), key);
            if (cmp > 0) {
                if (current_elem->right == NULL) {
                    current_elem->right = (StrMapNode*) malloc(sizeof(StrMapNode));
                    current_elem->right = map_init(current_elem->right, key);
                    return &current_elem->right->data;
                } else
                    return map_update(&current_elem->right, key);
            } else if (cmp < 0) {
                if (current_elem->left == NULL) {
                    current_elem->left = (StrMapNode *) malloc(sizeof(StrMapNode));
                    current_elem->left = map_init(current_elem->left, key);
                    return &current_elem->left->data;
                } else
                    return map_update(&current_elem->left, key);
            } else
                return &current_elem->data;
        }
    }
}


void map_release(StrMapNode **root) {
    StrMapNode* current_elem = *root;
    if (current_elem != NULL) {
        map_release(&current_elem->left);
        map_release(&current_elem->right);
        str_release(&current_elem->key);
        free(current_elem->left);
        free(current_elem->right);
    }
}

void map_post_order(StrMapNode **root, void(*work)(char* key, u_int32_t* data, void* work_data), void* work_data){
    if (work == NULL)
        return;
    else {
        if (*root != NULL) {
            StrMapNode *current_elem = *root;
            map_post_order(&current_elem->left, work, work_data);
            map_post_order(&current_elem->right, work, work_data);
            work(str_get(&current_elem->key), &current_elem->data, work_data);
        }
    }
}

