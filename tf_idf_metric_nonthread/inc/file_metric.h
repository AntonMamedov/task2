#pragma once
#include <stdlib.h>

#include "str_map.h"
#include "tf_idf_priority_queue.h"
#include "tf_idf_data.h"

//Структура содержащая имя файла и массив слов,встреченных в данном файле, а так же их метрик
typedef struct{
    char* file_name;
    WordTf_idf* word_list;
    Tf_IdfPriorityQueue idf_queue;
    size_t word_list_size;
}FileWordData;

//Инициализирует структуру FileWordData, поля структуру приравниваются соответствующим им знаечниям переданным в функцию
void file_word_data_init(FileWordData* data, char* filename, WordTf_idf* word_list, size_t word_list_size);
//Данная функция берет из файла слова и высчитывает их tf метрики
//Первый аргумент - путь к дирректории с файлами
//Второй аргумент - требующая заполнения структура, плпутно содержащая имя файла
//Третий аргумент - указатель на дерева, в котом происходит расчет частоты встречаемости слова во всех файлах диреткории
int get_file_metric(char* work_dir_name, FileWordData* data, StrMap* global_str_map);
int word_tf_idf_comparator(WordTf_idf* left, WordTf_idf* right);
void file_word_data_release(FileWordData* elem);
void file_word_data_releaser(FileWordData* elem);