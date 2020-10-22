#include <string.h>

#include "str_map.h"
//Так как дерево реализовано рекурсивно, пользовательским функциям
//принимающим в себя обертку над узлом дерева требуются локальные копии

//Инициализирует ноду дерева
//Первый элемент указатель на не инициализированную ноду
//Второй аргумент - ключ
StrMapNode* map_node_init(StrMapNode* elem, char* key);
//Локальная версия функци map_insert_or_search, за исключением того, что второй аргуент - нода дерева, 4 элемент рамер
StrMapData* local_map_insert_or_search(char *key, StrMapNode *node, int* flag, size_t* size);
//Локальная копия функции map_release, за исключением того, что принимает ноду дерева
void local_map_release(StrMapNode* node);
//Локальная копия функции map_pre_order, за исключением того, что вторым аргументом принимает ноду дерева
void local_map_pre_order(StrMapNode* node, void (*work)(StrMapData *, void *), void *data_for_work);

void map_init(StrMap *map) {
    map->root = NULL;
    map->size = 0;
}

StrMapData *map_insert_or_search(char *key, StrMap *map, int* flag){
    if (key == NULL || flag == NULL)
        return NULL;
    else {
        *flag = INSERTED;
        if (map->root == NULL) {
            map->root = (StrMapNode*)malloc(sizeof(StrMapNode));
            map->root = map_node_init(map->root, key);
            map->size+= 1;
            return &map->root->data;
        } else {
            int cmp = strcmp(str_get(&map->root->data.key), key);
            if (cmp > 0) {
                if (map->root->right == NULL) {
                    map->root->right = (StrMapNode*)malloc(sizeof(StrMapNode));
                    map->root->right = map_node_init(map->root->right, key);
                    map->size+=1;
                    return &map->root->right->data;
                } else
                    return local_map_insert_or_search(key, map->root->right, flag, &map->size);
            } else if (cmp < 0) {
                if (map->root->left == NULL) {
                    map->root->left = (StrMapNode*)malloc(sizeof(StrMapNode));
                    map->root->left = map_node_init(map->root->left, key);
                    map->size+=1;
                    return &map->root->left->data;
                } else
                    return local_map_insert_or_search(key, map->root->left, flag, &map->size);
            } else{
                *flag = FOUND;
                return &map->root->data;
            }
        }
    }
}

StrMapData* local_map_insert_or_search(char *key, StrMapNode *node, int* flag, size_t* size){
    if (key == NULL || flag == NULL || node == NULL)
        return NULL;
    else {
        int cmp = strcmp(str_get(&node->data.key), key);
        if (cmp > 0) {
            if (node->right == NULL) {
                node->right = (StrMapNode*)malloc(sizeof(StrMapNode));
                node->right = map_node_init(node->right, key);
                *size+=1;
                return &node->right->data;
            } else
                return local_map_insert_or_search(key, node->right, flag, size);
        } else if (cmp < 0) {
            if (node->left == NULL) {
                node->left = (StrMapNode*)malloc(sizeof(StrMapNode));
                node->left = map_node_init(node->left, key);
                *size+=1;
                return &node->left->data;
            } else
                return local_map_insert_or_search(key, node->left, flag, size);
        } else{
            *flag = FOUND;
            return &node->data;
        }

    }
}

void map_pre_order(StrMap *map, void (*work)(StrMapData* data, void* data_for_work), void *data_for_work){
    if (work == NULL)
        return;
    work(&map->root->data, data_for_work);
    local_map_pre_order(map->root->left, work, data_for_work);
    local_map_pre_order(map->root->right, work, data_for_work);
}

void local_map_pre_order(StrMapNode* node, void (*work)(StrMapData* data, void* data_for_work), void *data_for_work){
    if (node == NULL)
        return;
    work(&node->data, data_for_work);
    local_map_pre_order(node->left, work, data_for_work);
    local_map_pre_order(node->right, work, data_for_work);
}

void map_release(StrMap *map){
    local_map_release(map->root->left);
    local_map_release(map->root->right);
    str_release(&map->root->data.key);
    free(map->root->left);
    free(map->root->right);
    free(map->root);
    map->size = 0;
    map->root = NULL;
}

void local_map_release(StrMapNode* node){
    if (node == NULL)
        return;
    local_map_release(node->left);
    local_map_release(node->right);
    str_release(&node->data.key);
    free(node->left);
    free(node->right);
}

StrMapNode* map_node_init(StrMapNode* elem, char* key){
    elem->left = NULL;
    elem->right = NULL;
    str_init(key, &elem->data.key);
    elem->data.val = 0;
}