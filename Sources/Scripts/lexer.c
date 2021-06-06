//
// Created by Valentin on 6/5/2021.
//

#include "novelty.h"
#include <string.h>

static const char *REGISTRY_TYPE_STRING[] = {
        FOREACH_REGISTRYTYPE(GENERATE_STRING)
};

int is_registry_type(char *token)
{
    for (int i = 0; i < (sizeof(REGISTRY_TYPE_STRING) / sizeof(REGISTRY_TYPE_STRING[0])); i++) {
        if (strcmp(REGISTRY_TYPE_STRING[i], token) == 0)
            return i;
    }
    return -1;
}

void lexing_file_content(char **filesArray, unsigned int filesArraySize)
{
    char *tempLine;
    int lineSize = 0;
    int offset = 0;

    for (unsigned int i = 0; i < filesArraySize; i++) {
        for (int j = 0; filesArray[i][j]; j++) {
            lineSize++;
            if (filesArray[i][j] == '\n') {
                lineSize = (filesArray[i][j+1] == 0) ? lineSize - 1 : lineSize - 2;
                tempLine = malloc(sizeof(char) * lineSize + 1);
                tempLine[lineSize] = 0;
                strncpy(tempLine, filesArray[i] + offset, lineSize);
                offset = j + 1;
                lineSize = 0;
                printf("[DEBUG]:{%s}\n", tempLine);
                explode_from_line(tempLine);
                free(tempLine);
            }
        }
        offset = 0;
        lineSize = 0;
    }
}
