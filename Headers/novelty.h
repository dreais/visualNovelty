//
//  novelty.h
//  VisualNovelty
//
//  Created by Valentin Lattay on 03/06/2021.
//

#ifndef novelty_h
#define novelty_h

#include <stdlib.h>

struct keyVal {
    char key[24];
    char value[_MAX_PATH];
};

typedef struct {
    char moduleName[24];
    struct keyVal *component;
    int componentSize;
} settings;

// Launcher
#define MAX_MENU_CHOICES 4
void launcher_startup(void);

#endif /* novelty_h */
