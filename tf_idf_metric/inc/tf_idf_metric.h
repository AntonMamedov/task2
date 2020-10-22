#pragma once
#include "str_map.h"

typedef struct {
    char* word;
    double tf;
}WordTf;

typedef struct{
    char* file_name;
    WordTf* word_list;
    size_t word_list_size;
}FileWordData;

void file_word_data_init(FileWordData* data, char* filename, WordTf* word_list, size_t word_list_size);
int get_file_metric(FileWordData* data, char* work_dir_name, StrMapNode** global_word_tree);