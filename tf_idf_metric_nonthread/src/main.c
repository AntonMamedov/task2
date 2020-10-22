#include <stdio.h>
#include <math.h>
#include <dirent.h>

#include "vec.h"
#include "str_mab.h"
#include "file_metric.h"
#include "user_info_macro.h"

#define MINIMAL_FILE_IN_DIR_NUM 2
#define NUMBER_OF_TOP_WORDS 5

int main(int argc, char** argv) {
    if (argc < 2){
        return 0;
    }
    struct dirent *dir;
    DIR *sought_dir = opendir(argv[1]);
    if (sought_dir != NULL){
        Vector file_info_vec;
        vec_init(&file_info_vec);
        while ((dir = readdir(sought_dir)) != NULL) {
            if (dir->d_type == DT_REG) {
                FileWordData *file_data = (FileWordData *) malloc(sizeof(FileWordData));
                file_word_data_init(file_data, dir->d_name, NULL, 0);
                vec_push(file_data, &file_info_vec);
            }
        }
        closedir(sought_dir);
        if (file_info_vec.size < MINIMAL_FILE_IN_DIR_NUM){
            fprintf(stderr, "%s\n", LOW_FILES);
        }
        else {
            StrMap global_word_map;
            map_init(&global_word_map);
            Vector error_vector;
            vec_init(&error_vector);
            for (size_t i = 0; i < file_info_vec.size; i++) {
                FileWordData *file_data = vec_get(i, &file_info_vec);
                if (file_data != NULL) {
                    if (get_file_metric(argv[1], file_data, &global_word_map) == -1)
                        vec_push(file_data->file_name, &error_vector);
                }
            }
            for (size_t i = 0; i < file_info_vec.size; i++) {
                FileWordData *file_data = vec_get(i, &file_info_vec);
                for (size_t j = 0; j < file_data->word_list_size; j++) {
                    file_data->word_list[j].tf_idf =
                            file_data->word_list[j].tf *
                            log10((double) file_info_vec.size / (double) file_data->word_list[j].word->val);
                }
            }
            for (size_t i = 0; i < file_info_vec.size; i++) {
                FileWordData *file_data = vec_get(i, &file_info_vec);
                for (size_t j = 0; j < file_data->word_list_size; j++) {
                    qsort(file_data->word_list, file_data->word_list_size - 1,
                          sizeof(WordTf_idf), word_tf_idf_comparator);
                }
            }
            if (error_vector.size > 0){
                fprintf(stderr,"%s\n", IMPOSSIBLE_TO_OPEN);
                for (size_t i = 0; i < error_vector.size; i++)
                    fprintf(stderr,"  %s\n", (char*)vec_get(i, &error_vector));
            }
            for (size_t i = 0; i < file_info_vec.size; i++) {
                FileWordData *file_data = vec_get(i, &file_info_vec);
                printf("%s\n", file_data->file_name);
                for (size_t j = 0; j < NUMBER_OF_TOP_WORDS; j++) {
                    if (j < file_data->word_list_size)
                        printf("  %s\n", str_get(&file_data->word_list[j].word->key));
                }
            }
            map_release(&global_word_map);
            vec_release(NULL, &error_vector);
        }
        vec_release(free, &file_info_vec);
    }
    else{

    }
    return 0;
}
