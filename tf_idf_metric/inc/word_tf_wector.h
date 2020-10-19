#ifndef TF_IDF_METRIC_VECTOR_H
#define TF_IDF_METRIC_VECTOR_H

#endif //TF_IDF_METRIC_VECTOR_H
#include <stdlib.h>
#include <monetary.h>


#define DEFAULT_VECTOR_SIZE 256
typedef struct WordTf{
    char* word;
    double tf;
}WordTf;

typedef struct {
    WordTf* vector;
    ssize_t size;
    ssize_t alloc_size;
}WordTfVector;

void vec_init(WordTfVector* vec);

//Добавление элемента в вектор
WordTf* vec_push(char* word, u_int32_t tf, WordTfVector* vec);
