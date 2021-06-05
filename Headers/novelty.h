//
//  novelty.h
//  VisualNovelty
//
//  Created by Valentin Lattay on 03/06/2021.
//

#ifndef novelty_h
#define novelty_h

#include <stdlib.h>
#include <stdio.h>

struct keyVal {
    char key[24];
    char value[_MAX_PATH];
};

typedef struct {
    char moduleName[24];
    struct keyVal *component;
    int componentSize;
} settings;

typedef enum {
    Volume,
    Chapter,
    Dialog
} registryType;

typedef struct {
    registryType type;
    void *ptr_param; // data; cast to proper type with registryType
    struct keyVal *args;
} registry;

typedef struct {
    settings *gameSettings;
    registry *gameRegistry;
} gameContent;

// Launcher
#define MAX_MENU_CHOICES 4
void launcher_startup(void);
char *fetch_file(FILE *currentFile);

// BBBCode
#define MAX_SCRIPT_PATH 2048
void registry_input(void);


#endif /* novelty_h */
