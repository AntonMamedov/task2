#include "file_metric.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define  MAX_WORD_LENGTH 256
#define  MAX_FILE_PATH_LENGTH 1024

//Данная структура используется при обходе дерева, для передачи в качестве аргумента для функции выполняющей работу
//на надое дерева
typedef struct{
    StrMap* global_word_tree;  //Указатель на дерева подсчета встречаемости слова во всех файлах
    WordTf_idf* word_list;     //Массив слова встреченных в файле
    size_t word_list_size;     //Размер массива слов
    size_t word_list_index;    //Текущий индекс для вставки в массив слов
}WordListFillingData;

//Заполняет дерево слов содержащихся в конкретном файле
//После отработки этой функции, получается дерево, поле data каждого узла которого содержит в поле key-слово, а в поле
// data - количество раз, когда слово встретилось в файле
//Первый аргумент - путь к файлу
//Второй аргумент - дерево слов в файле
int get_words(char* file_path, StrMap* word_map);
//Функция передающаяся в качестве аргумент в функцию обхода дерева
//Она заполняет дерево частоты встречаемости слова во всех файлах из ключей дерева встречаемости слова в конкретном файле
//Значение val, привязанное ко всем словам дерева подсчета слов во всех файлах содержащихся в дереве подсчета в
//конкретном файле инкрементируется
//Каждое слово, содержащееся в дереве подсчета слов в конкретном файле вносится в массив w0rd_list, привязанный к файле
//Для каждого слова содержащегося в файле высчитывается tf
//Первый аргумент - указатель на данные ноды дерева подсчета слов в конкретном файле
//Второй аргумент - структура содержащая информацию для работы данной функции
void word_list_filling(StrMapData* data, WordListFillingData* work_data);

void file_word_data_init(FileWordData* data, char *filename, WordTf_idf *word_list, size_t word_list_size){
    data->file_name = strdup(filename);
    data->word_list = word_list;
    data->word_list_size = word_list_size;
}

int get_file_metric(char* work_dir_name, FileWordData* data, StrMap* global_str_map){
    if (data == NULL || work_dir_name == NULL)
        return - 1;
    else {
        //Объединение путя к директории и имя файла
        char file_path[MAX_FILE_PATH_LENGTH];
        snprintf(file_path, sizeof file_path, "%s%s", work_dir_name, data->file_name);
        //Инициализация дерева подсчета слов в конкретном файле
        StrMap word_map;
        map_init(&word_map);
        //Заполнение дерева
        //Если файл не открылся, возвращаем -1
        if (get_words(file_path, &word_map) == 0){
            //Создаем массив слов в файле, равный размеру дерева
            data->word_list = (WordTf_idf*)malloc(sizeof(WordTf_idf) * word_map.size);
            data->word_list_size = word_map.size;
            WordListFillingData filling_data =
                    {global_str_map,
                     data->word_list,
                     data->word_list_size,
                     0};
            //Инкрементируем счетчик слов в глобальном дереве и заполняем массив слов в файле
            map_pre_order(&word_map, word_list_filling, &filling_data);
            map_release(&word_map);
            return 0;
        }
        else
            return -1;

    }
}

int get_words(char* file_path, StrMap* word_map){
    FILE* file = fopen(file_path, "r");
    if (file == NULL)
        return -1;
    else {
        char buf[MAX_WORD_LENGTH + 1];
        char sym;
        for (int len = 0; (sym = fgetc(file)) != EOF; len++) {
            if (isalnum(sym) == 0 && len != 0) {
                buf[len] = '\0';
                int flag = 0;
                StrMapData *data = map_insert_or_search(buf,word_map, &len);
                data->val += 1;
                len = -1;
            } else if (isalnum(sym) == 0 && len == 0)
                len--;
            else
                buf[len] = tolower(sym);
        }
        fclose(file);
        return 0;
    }
}

void word_list_filling(StrMapData* data, WordListFillingData* work_data){
    int flag = 0;
    //Добавляем в дерево подсчета частоты встречаемости слова во всех файлах слово и инкрментируем счетчик слов
    StrMapData* global_tre_node_data = map_insert_or_search(str_get(&data->key), work_data->global_word_tree, &flag);
    global_tre_node_data->val+= 1;
    //В текущий индекс массива вставляем указатель на поле дата глобального дерева, содержащее слово
    work_data->word_list[work_data->word_list_index].word = global_tre_node_data;
    work_data->word_list[work_data->word_list_index].tf = (double)data->val / (double)work_data->word_list_size;
    //Инкрементируем индекс
    work_data->word_list_index+= 1;
}

int word_tf_idf_comparator(WordTf_idf *left, WordTf_idf *right) {
    return left->tf_idf < right->tf_idf;
}