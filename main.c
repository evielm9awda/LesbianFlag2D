#include "raylib.h"
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define L_DARK_ORANGE  (Color){ 213, 45, 0, 255 }
#define L_ORANGE       (Color){ 239, 118, 39, 255 }
#define L_LIGHT_ORANGE (Color){ 255, 154, 86, 255 }
#define L_WHITE        (Color){ 255, 255, 255, 255 }
#define L_LIGHT_PINK   (Color){ 255, 118, 164, 255 }
#define L_PINK         (Color){ 255, 86, 122, 255 }
#define L_DARK_PINK    (Color){ 212, 0, 88, 255 }

void DrawWavyFlag2D(void);
void DrawMenu(void);
void DrawAbout(void);

typedef enum {
    MENU,
    FLAG,
    ABOUT
} GameState;

GameState currentState = MENU;

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Lesbian Flag 2D");

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_BACKSPACE)) {
            currentState = MENU;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch(currentState) {
            case MENU:
                DrawMenu();
                break;
            case FLAG:
                DrawWavyFlag2D();
                DrawText("Press BACKSPACE to return to menu", 10, 10, 20, BLACK);
                break;
            case ABOUT:
                DrawAbout();
                break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void DrawWavyFlag2D(void)
{
    const int stripes = 7;
    const float stripeHeight = 40.0f; 
    const float amplitude = 30.0f; 
    const float frequency = 0.05f; 
    const float speed = 3.0f; 
    float time = (float)GetTime() * speed;

    Color colors[] = {L_DARK_ORANGE, L_ORANGE, L_LIGHT_ORANGE, L_WHITE, L_LIGHT_PINK, L_PINK, L_DARK_PINK};

    // Calculate the flag's starting y position to center it vertically
    float flagHeight = stripeHeight * stripes;
    float startY = (WINDOW_HEIGHT - flagHeight) / 2;

    for (int y = 0; y < flagHeight; y++)
    {
        int stripeIndex = y / stripeHeight;
        float xOffset = sinf((float)y * frequency + time) * amplitude;

        DrawLineEx((Vector2){xOffset, startY + y}, (Vector2){WINDOW_WIDTH + xOffset, startY + y}, 2, colors[stripeIndex]);
    }

    const char *quote = "\"Love is love, and it knows no gender.\"";
    DrawText(quote, (WINDOW_WIDTH - MeasureText(quote, 20)) / 2, startY + flagHeight + 20, 20, L_PINK);
}

void DrawMenu(void)
{
    int centerX = WINDOW_WIDTH / 2;
    int centerY = WINDOW_HEIGHT / 2;

    DrawRectangleGradientV(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, L_DARK_PINK, L_LIGHT_ORANGE);

    DrawText("Lesbian Flag 2D", centerX - MeasureText("Lesbian Flag 2D", 40) / 2, centerY - 180, 40, L_WHITE);

    const char *quote = "\"Love is love, and it knows no gender.\"";
    DrawText(quote, centerX - MeasureText(quote, 20) / 2, centerY - 110, 20, L_WHITE);

    Rectangle startBtn = {centerX - 100, centerY - 30, 200, 50};
    DrawRectangleRec(startBtn, L_PINK);
    DrawText("Start", centerX - MeasureText("Start", 20) / 2, centerY - 15, 20, L_WHITE);

    Rectangle aboutBtn = {centerX - 100, centerY + 40, 200, 50};
    DrawRectangleRec(aboutBtn, L_ORANGE);
    DrawText("About", centerX - MeasureText("About", 20) / 2, centerY + 55, 20, L_WHITE);

    Rectangle exitBtn = {centerX - 100, centerY + 110, 200, 50};
    DrawRectangleRec(exitBtn, L_LIGHT_PINK);
    DrawText("Exit", centerX - MeasureText("Exit", 20) / 2, centerY + 125, 20, L_WHITE);

    DrawText("TOMORIN KATSLM ELIKOM", 10, WINDOW_HEIGHT - 30, 20, L_WHITE);

    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, startBtn)) {
        DrawRectangleLinesEx(startBtn, 2, L_WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentState = FLAG;
        }
    }
    if (CheckCollisionPointRec(mousePoint, aboutBtn)) {
        DrawRectangleLinesEx(aboutBtn, 2, L_WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentState = ABOUT;
        }
    }
    if (CheckCollisionPointRec(mousePoint, exitBtn)) {
        DrawRectangleLinesEx(exitBtn, 2, L_WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            CloseWindow();
        }
    }
}

void DrawAbout(void)
{
    int centerX = WINDOW_WIDTH / 2;

    DrawRectangleGradientV(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, L_LIGHT_PINK, L_LIGHT_ORANGE);

    DrawText("About Lesbian Flag 2D", centerX - MeasureText("About Lesbian Flag 2D", 30) / 2, 50, 30, L_WHITE);

    const char *aboutText[] = {
        "This program displays the lesbian pride flag in 2D.",
        "It uses Raylib for graphics and animation.",
        "",
        "The lesbian flag colors represent:",
        "- Dark Orange: Gender non-conformity",
        "- Orange/Light Orange: Independence",
        "- White: Unique relationships to womanhood",
        "- Pink shades: Serenity, love, and femininity",
        "",
        "Programmed with pride by evie lm9awda",
        "",
        "Press BACKSPACE to return to the main menu"
    };

    for (int i = 0; i < sizeof(aboutText) / sizeof(aboutText[0]); i++) {
        DrawText(aboutText[i], 50, 120 + i * 30, 20, L_WHITE);
    }

    int stripeHeight = 10;
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight, WINDOW_WIDTH, stripeHeight, L_DARK_ORANGE);
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight * 2, WINDOW_WIDTH, stripeHeight, L_ORANGE);
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight * 3, WINDOW_WIDTH, stripeHeight, L_LIGHT_ORANGE);
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight * 4, WINDOW_WIDTH, stripeHeight, L_WHITE);
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight * 5, WINDOW_WIDTH, stripeHeight, L_LIGHT_PINK);
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight * 6, WINDOW_WIDTH, stripeHeight, L_PINK);
    DrawRectangle(0, WINDOW_HEIGHT - stripeHeight * 7, WINDOW_WIDTH, stripeHeight, L_DARK_PINK);
}
