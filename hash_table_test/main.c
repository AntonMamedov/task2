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
    uint32_t hash = 0;

    for (size_t i = 0; i < strlen(str); i++) {
        hash = hash * a + str[i];
        a = a * b;
    }
    return (hash & 0x7FFFFFFF);
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
int extend(HashTableNode* table, HashTableMetaData* meta_data){
    if (table == NULL)
        return -1;
    else {
        if (meta_data->extend_index == TABLE_SIZES_SIZE - 1)
            return -1;
        else {
            uint32_t table_size = table_sizes[meta_data->extend_index + 1];
            HashTableNode* new_table = (HashTableNode*)malloc(sizeof(HashTableNode) * table_size);
            for (uint32_t i = 0; i < meta_data->table_size; i++){
                
            }
        }
    }
}

int ht_insert(char* key,HashTableNode* table, HashTableMetaData* meta_data){
    uint32_t index = RShash(key) % meta_data->table_size;
    for (; index < meta_data->table_size; index++){
        if (table[index].key == NULL){
            table[index].key = strdup(key);
            return index;
        }
        else {
            if (strcmp(table->key, key) == 0)
                return index;
        }

    }
}

int ht_update(char* key, HashTableNode* table, uint16_t true_size,uint16_t* table_size){
    if ()
}


int main() {
    return 0;
}
//446371745