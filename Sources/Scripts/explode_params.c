//
// Created by Valentin on 6/5/2021.
//

#include <novelty.h>
#include <string.h>

static registry tokenize(char *line)
{
    char *mainStr, *subStr, *token, *subToken;
    char mainDelim[] = " ", subDelim[] = "=";
    char *saveMainPtr, *saveSubPtr;
    registry returnRegistry = {0};
    int i;

    for (mainStr = line; ; i++, mainStr = NULL) {
        token = strtok_r(mainStr, mainDelim, &saveMainPtr);
        if (token == NULL)
            break;
        printf("%s\n", token);

        for (i = 0, subStr = token; ; i++, subStr = NULL) {
            subToken = strtok_r(subStr, subDelim, &saveSubPtr);
            if (subToken == NULL)
                break;
            printf("\t%s\n", subToken);
        }
    }
    return returnRegistry;
}

void explode_from_line(char *line)
{
    unsigned int length = strlen(line);
    char *tmpLine;
    registry gameRegistry;

    if (line[0] == '[' && line[length - 1] == ']') {
        tmpLine = malloc(sizeof(char) * length - 2);
        strncpy(tmpLine, line + 1, length - 2);
        tmpLine[length - 2] = 0;
        tokenize(tmpLine);
        return;
    }
}