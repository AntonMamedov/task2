#include "tf_idf_metric.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  MAX_WORD_LENGTH 256
#define  MAX_FILE_PATH_LENGTH 1024

typedef struct{
    StrMapNode** global_word_tree;
    WordTf* word_list;
    size_t word_list_size;
    size_t word_list_index;
}WordListFillingData;
//
void pr(char* key, int* data, void* dw){
    printf("%s: %d\n", key, *data);
}
///
void word_list_filling(char* key, uint32_t* data, WordListFillingData* work_data);

int get_file_metric(FileWordData *data, char *work_dir_name, StrMapNode** global_word_tree) {
    if (data == NULL || work_dir_name == NULL)
        return - 1;
    else{
        char file_path[MAX_FILE_PATH_LENGTH];
        snprintf(file_path, sizeof file_path, "%s%s", work_dir_name, data->file_name);
        FILE* file = fopen(file_path, "r");
        if (file == NULL)
            return -2;
        else {
            StrMapNode *word_tree = NULL;
            char buf[MAX_WORD_LENGTH + 1];
            char sym;
            int word_count = 0;
            int inc = 0;
            for (int len = 0; (sym = fgetc(file)) != EOF; len++) {
                if (isalnum(sym) == 0 && len != 0) {
                    buf[len] = '\0';
                    int* count = map_update(&word_tree, buf);
                    if (*count == 0)
                        word_count++;
                    *count += 1;

                    len = -1;
                } else if (isalnum(sym) == 0 && len == 0)
                    len--;
                else
                    buf[len] = tolower(sym);
            }
            fclose(file);
//            data->word_list = (WordTf*)malloc(sizeof(WordTf) * word_count);
//            data->word_list_size = word_count;
//            WordListFillingData filling_data =
//                    {global_word_tree,
//                     data->word_list,
//                     data->word_list_size,
//                     0};
           // map_post_order(&word_tree,word_list_filling, &filling_data);
            map_post_order(&word_tree,pr, NULL);
            map_release(&word_tree);
            return 0;
        }
    }
}
void file_word_data_init(FileWordData* data, char *filename, WordTf *word_list, size_t word_list_size){
    data->file_name = strdup(filename);
    data->word_list = word_list;
    data->word_list_size = word_list_size;
}

void word_list_filling(char* key, uint32_t* data, WordListFillingData* work_data){
    StrMapNode* elem = map_update(work_data->global_word_tree, key);
    elem->data+= 1;
    work_data->word_list[work_data->word_list_index].word = key;
    double  a = work_data->word_list_size;
    double b = (double)*data;
    work_data->word_list[work_data->word_list_index].tf = (double)work_data->word_list_size / (double)*data;
}

