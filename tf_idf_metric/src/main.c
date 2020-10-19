#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "str_map.h"

void print(char* key, int* data, void* dw){
    printf("%s: %d\n", key, *data);
}
#define  MAX_WORD_LENGTH 256


int main(int argc, char** argv) {
    if (argc < 2){
        return 0;
    }
    FILE* file = fopen(argv[1], "r");
    StrMapNode* word_tree = NULL;
    char buf[MAX_WORD_LENGTH + 1];
    char sym;
    int s = 0;
    for (int len = 0; (sym = fgetc(file)) != EOF; len++){
        if (isalnum(sym) == 0 && len != 0){
            buf[len] = '\0';
            u_int32_t* count = map_update(&word_tree, buf);
            if (*count == 0)
                s++;
            *count = *count + 1;
            len = -1;
        }
        else if(isalnum(sym) == 0 && len == 0)
            len--;
        else
            buf[len] = tolower(sym);
    }
    fclose(file);
    map_post_order(&word_tree, print, NULL);
    printf("%d", s);
    map_release(&word_tree);
    free(word_tree);
    return 0;
}
