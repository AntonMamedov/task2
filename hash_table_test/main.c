#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZES_SIZE 5


typedef struct{
    char* key;
    uint16_t value;
}HashTableNode;

typedef struct{
    uint32_t table_size;
    uint32_t true_table_size;
    uint8_t extend_index;
}HashTableMetaData;

uint32_t table_sizes[TABLE_SIZES_SIZE] = {11, 13, 17, 19, 23};
        // {15013, 30011, 60013, 120011, 240007 };

//Алгоритм хеширования RS(Роберта Седжвика)
uint32_t RShash(const char* str) {
    const uint32_t b = 378551;
    uint32_t a = 63689;
    const uint32_t hash_const = 0x7FFFFFFF;
    uint32_t hash = 0;

    for (size_t i = 0; i < strlen(str); i++) {
        hash = hash * a + str[i];
        a = a * b;
    }
    return (hash & hash_const);
}


////JS Hash
//unsigned int second_hash(const char* str)
//{
//    uint32_t hash = 1315423911;
//    const uint8_t left_shift = 5;
//    const uint8_t right_shift = 2;
//    for(size_t i = 0; i < strlen(str); i++)
//        hash ^= ((hash << left_shift) + str[i] + (hash >> right_shift));
//
//    return (hash & 0x7FFFFFFF);
//}
int ht_insert(const char* key,HashTableNode* table, HashTableMetaData* meta_data){
    meta_data->true_table_size+= 1;
    if (meta_data->true_table_size == meta_data->table_size)
        return -1;
    else {
        uint32_t index = RShash(key) % meta_data->table_size;
        for (; index < meta_data->table_size; index++) {
            if (table[index].key == NULL) {
                table[index].key = strdup(key);
                return index;
            } else {
                if (strcmp(table->key, key) == 0)
                    return index;
            }
        }
    }
}

int ht_extend(HashTableNode* table, HashTableMetaData* meta_data){
    if (table == NULL)
        return -1;
    else {
        if (meta_data->extend_index == TABLE_SIZES_SIZE - 1)
            return -1;
        else {
            HashTableNode* new_table = (HashTableNode*)malloc(sizeof(HashTableNode) * table_sizes[meta_data->extend_index + 1]);
            if (new_table == NULL)
                return -1;
            else {
                uint32_t prev_table_size = meta_data->table_size;
                meta_data->table_size = table_sizes[meta_data->extend_index + 1];
                meta_data->extend_index+= 1;
                for (uint32_t i = 0; i < prev_table_size; i++) {
                    int index = ht_insert(table[i].key, new_table, meta_data);
                    new_table[index].value = table[i].value;
                }
                free(table);
                table = new_table;
                return 0;
            }
        }
    }
}

int ht_update(char* key, HashTableNode** hash_table, HashTableMetaData* meta_data){
    if (meta_data == NULL || hash_table == NULL)
        return -1;
    else {
        if (*hash_table == NULL) {
            *hash_table = (HashTableNode*)malloc(sizeof(HashTableNode) * table_sizes[0]);
            meta_data->table_size = table_sizes[0];
            meta_data->extend_index = 0;
            meta_data->true_table_size = 0;
            return ht_insert(key, *hash_table, meta_data);
        }
        else {
            if ((double) meta_data->table_size / (double) meta_data->table_size < 1.4) {
                if (ht_extend(*hash_table, meta_data) == -1)
                    return -1;
            }
            return ht_insert(key, *hash_table, meta_data);
        }
    }

}


int main() {
    char* a1 = "111";
    char* a2 = "abc";
    char* a3 = "dfg";
    char* a4 = "123fa";
    char* a5 = "gsnajk";
    char* a6 = "sa12da";
    char* a7 = "qwerty";
    char* a8 = "123";
    char* a9 = "ghjk";
    char* a10 = "12";
    HashTableNode* table = NULL;
    HashTableMetaData meta_data;
    int index = ht_update(a1, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a2, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a3, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a4, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a5, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a6, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a7, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a8, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a9, &table, & meta_data);
    printf("%d\n", index);
    index = ht_update(a10, &table, & meta_data);
    printf("%d\n", index);

    return 0;
}
//446371745