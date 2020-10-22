#pragma once
#define STATIC_STR_DEFAULT_LENGTH 15
#include <stdlib.h>

//Если строка вместе с /0 меньше 16 байт, используем small string optimization
typedef union{
    char static_str[STATIC_STR_DEFAULT_LENGTH + 1];
    char* dynamic_str;
}StringData;

//Структура, инкапсулирующая строку, нужна для приминения small string optimization
typedef struct String{
    size_t length;
    StringData str;
}String;

//Инициализация структуры строкой
//Первый аргумент - строка, которой будет инициализирована структура
//Второй аргумент - сама структура
char* str_init(const char* src, String* dest);
//Взятие указателя на строку внутри структуры String
char* str_get(String* str);
//В случае, если память была динамически алоцирована - очищает ее
void str_release(String* str);