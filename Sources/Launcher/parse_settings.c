//
// Created by Valentin on 6/4/2021.
//

#include "novelty.h"
#include "launcher.h"
#include <stdio.h>
#include <unistd.h>

static struct keyVal display_default[] = {
        {"resolution", "0"},
        {"filepath", "."},
        {"fps", "60"}
};

static struct keyVal sounds_default[] = {
        {"master", "0.95"},
        {"background", "0.95"},
        {"ambiant", "0.95"},
        {"voices", "0.95"}
};

static struct keyVal control_default[] = {
        {"hide_hud", "h"},
        {"skip", "CTRL"},
        {"menu", "ESC"}
};

static settings DEFAULT_SETTINGS[3] = {
        {"display", display_default, 3},
        {"sounds", sounds_default, 4},
        {"control", control_default, 3}
};

char *fetch_file(FILE *settingsFile)
{
    char *fileContent = NULL;
    long fileSize;

    fseek(settingsFile, 0, SEEK_END);
    fileSize = ftell(settingsFile);
    fseek(settingsFile, 0, SEEK_SET);
    fileContent = malloc(fileSize + 1);
    fread(fileContent, 1, fileSize, settingsFile);
    fclose(settingsFile);
    fileContent[fileSize] = 0;
    return fileContent;
}

void parse_file(FILE *settingsFile)
{
    char *fileContent;

    fileContent = fetch_file(settingsFile);
    printf("%s\n", fileContent);
}

void read_settings()
{
    FILE *settingsFile;

    if (access(DEFAULT_FILENAME, F_OK) == 0) {
        // IF FILE EXISTS
        settingsFile = fopen(DEFAULT_FILENAME, "rb");
        parse_file(settingsFile);
    } else {
        // IF FILE DOES NOT EXIST
        settingsFile = fopen(DEFAULT_FILENAME, "wb");
        for (int i = 0; i < 3; i++) {
            fprintf(settingsFile, "[%s]\n", DEFAULT_SETTINGS[i].moduleName);
            for (int j = 0; j < DEFAULT_SETTINGS[i].componentSize; j++) {
                char *tmpKey = DEFAULT_SETTINGS[i].component[j].key;
                char *tmpVal = DEFAULT_SETTINGS[i].component[j].value;

                fprintf(settingsFile, "%s:%s\n", tmpKey, tmpVal);
            }
            fprintf(settingsFile, "\n"); // for clarity
        }
    }
}
