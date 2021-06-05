//
//  launcher.c
//  VisualNovelty
//
//  Created by Valentin Lattay on 03/06/2021.
//

#include <stdio.h>
#include "raylib.h"
#include "novelty.h"
#include "launcher.h"

void launcher_startup(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	Vector2 mousePos;
	Rectangle menuChoices[MAX_MENU_CHOICES] = { 0 };
	const char choicesName[MAX_MENU_CHOICES][80] = {
		"Play",
		"Display",
		"Sound",
		"Control"
	};
	settings *gameSettings;

	for (int i = 0; i < MAX_MENU_CHOICES; i++) {
		menuChoices[i].x		=	40.0;
		menuChoices[i].y		=	40.0 + 30.0 * i;
		menuChoices[i].width	=	screenWidth - 30.0;
		menuChoices[i].height	=	30.0;
	}
	// TODO: read from file
	gameSettings = read_settings();

	InitWindow(screenWidth, screenHeight, "Visual Novelty - Launcher");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		mousePos = GetMousePosition();
		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (int i = 0; i < MAX_MENU_CHOICES; i++) {
			DrawTextRec(GetFontDefault(), choicesName[i], menuChoices[i], 30.0, 1.0, true, BLACK);
		}
		for (int i = 0; i < MAX_MENU_CHOICES; i++) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				if (CheckCollisionPointRec(mousePos, menuChoices[i])) {
					printf("Clicked on:\t%s\n", choicesName[i]);
				}
			}
		}
		EndDrawing();
	}
	CloseWindow();
	// TODO: write to file
}
