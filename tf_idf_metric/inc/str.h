#ifndef TF_IDF_METRIC_STR_H
#define TF_IDF_METRIC_STR_H

#endif //TF_IDF_METRIC_STR_H
#define STATIC_STR_DEFAULT_LENGTH 15
#include <stdlib.h>

typedef union{
    char static_str[STATIC_STR_DEFAULT_LENGTH + 1];
    char* dynamic_str;
}StringData;

typedef struct String{
    size_t length;
    StringData str;
}String;

char* str_init(const char* src, String* dest);
char* str_get(String* str);
void str_release(String* str);