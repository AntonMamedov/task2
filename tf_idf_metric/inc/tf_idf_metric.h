
#ifndef TF_IDF_METRIC_TF_IDF_METRIC_H
#define TF_IDF_METRIC_TF_IDF_METRIC_H

#endif //TF_IDF_METRIC_TF_IDF_METRIC_H

#include <word_tf_wector.h>

typedef struct FileWordData{
    char* file_name;
    WordTfVector word_list;
}FileWordData;

void get_file_metric(char* file_name, FileWordData* data, word)