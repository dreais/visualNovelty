//
// Created by Valentin on 6/5/2021.
//

#include <stdio.h>
#include "userConfig.h"
#include "novelty.h"

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

static char fullScriptPath[MAX_SCRIPT_PATH] = {0};

// SRC: https://stackoverflow.com/questions/5309471/getting-file-extension-in-c
static const char *get_filename_ext(const char *filename)
{
    const char *dot = strrchr(filename, '.');

    if(!dot || dot == filename)
        return "";
    return dot + 1;
}

static void file_into_array(const char fileName[260], char **filesArray, unsigned int filesArraySize)
{
    char fullPath[MAX_SCRIPT_PATH] = {0};
    FILE *currentFile;
    char *fileContent;
    char *debug;

    strcat(fullPath, fullScriptPath);
    strcat(fullPath, fileName);
    currentFile = fopen(fullPath, "rb");
    fileContent = fetch_file(currentFile);
    filesArray = realloc(filesArray, sizeof(char *) * filesArraySize);
    filesArray[filesArraySize - 1] = strdup(fileContent);
    printf("%s\n", filesArray[filesArraySize - 1]);
    debug = filesArray[filesArraySize - 1];
    //printf("{{%s}}\n", fileContent);

}

static void iterate_directory(DIR *scriptDir)
{
    struct dirent *currentFile;
    unsigned int filesArraySize = 0;
    char **filesArray = malloc(sizeof(char *) * filesArraySize);

    while ((currentFile = readdir(scriptDir)) != NULL) {
        if (currentFile->d_name[0] != '.') {
            if (strcmp(get_filename_ext(currentFile->d_name), ".bbc") != 0) {
                filesArraySize++;
                file_into_array(currentFile->d_name, filesArray, filesArraySize);
            }
        }
    }
    lexing_file_content(filesArray, filesArraySize);
    exit(-1);
}

void registry_input(void)
{
    DIR *scriptDir;

    getcwd(fullScriptPath, MAX_SCRIPT_PATH);
    strcat(fullScriptPath, RELATIVE_PATH);
    scriptDir = opendir(fullScriptPath);
    if (scriptDir == NULL) {
        // TODO: Handle error here
        return;
    }
    iterate_directory(scriptDir);
}
