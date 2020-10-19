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

uint32_t table_sizes[TABLE_SIZES_SIZE] = {15013, 30011, 60013, 120011, 240007 };

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
int ht_insert(char* key,HashTableNode* table, HashTableMetaData* meta_data){
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

int ht_update(char* key, HashTableNode* table, HashTableMetaData* meta_data){
    if (meta_data == NULL)
        return -1;
    else {
        if (table == NULL) {
            table = (HashTableNode*)malloc(sizeof(HashTableNode) * table_sizes[0]);
            meta_data->table_size == table_sizes[0];
            meta_data->extend_index = 0;
            meta_data->true_table_size = 0;
            return ht_insert(key, table, meta_data);
        }
        else {
            if ((double) meta_data->table_size / (double) meta_data->table_size < 1.4) {
                if (ht_extend(table, meta_data) == -1)
                    return -1;
            }
            return ht_insert(key, table, meta_data);
        }
    }

}


int main() {
    uint32_t a = 15;
    uint32_t b = 10;
    printf("%f", (double)a / (double)b);
    return 0;
}
//446371745