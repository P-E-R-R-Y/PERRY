
#include "raylib.h"
#include "Event.hpp"

int main(int arg, const char **argv)
{
  // Initialization
  const int screenWidth = 1280;
  const int screenHeight = 768;
  const char *windowTitle = "Hello world!";
  const char *message = "Hello world! It's great to be here.";
  const int fontSize = 40;
  const float msgSpacing = 1.0f;
  Event *event = new Event();

  InitWindow(screenWidth, screenHeight, windowTitle);
  event->addBool(1, []() { return IsKeyPressed(KEY_SPACE); });
  event->addBool(2, []() { return IsKeyDown(KEY_A); });
  event->addBool(3, []() { return IsKeyDown(KEY_ONE); });
  event->addBool(4, []() { return IsKeyDown(KEY_TWO); });
  event->addBool(5, []() { return IsKeyDown(KEY_THREE); });
  event->addBool(6, []() { return IsKeyDown(KEY_FOUR); });
  event->addBool(7, []() { return IsKeyDown(KEY_FIVE); });
  event->addBool(8, []() { return IsKeyDown(KEY_SIX); });
  event->addBool(9, []() { return IsKeyDown(KEY_SEVEN); });
  event->addBool(10, []() { return IsKeyDown(KEY_EIGHT); });
  event->addBool(11, []() { return IsKeyDown(KEY_NINE); });
  event->addBool(12, []() { return IsKeyDown(KEY_ZERO); });
  event->addBool(13, []() { return IsKeyDown(KEY_APOSTROPHE); });
  event->addBool(14, []() { return IsKeyDown(KEY_COMMA ); });
  event->addBool(14, []() { return IsKeyDown(KEY_COMMA ); });

  // NOTE: The following only works after calling InitWindow() (i.e,. RayLib is initialized)
  const Font font = GetFontDefault();
  const Vector2 msgSize = MeasureTextEx(font, message, fontSize, msgSpacing);
  const Vector2 msgPos = Vector2{(screenWidth - msgSize.x) / 2, (screenHeight - msgSize.y) / 2};
  SetTargetFPS(60);
  // Main loop
  while (!WindowShouldClose())
  {
    // Update the display
    BeginDrawing();
    ClearBackground(RAYWHITE);

    //IsKeyPressed(KEY_SPACE) ? DrawText("Space is down", 10, 10, 20, RED) : DrawText("Space is up", 10, 10, 20, RED);
    event->getBool(1) ? DrawText("Space is down", 10, 10, 20, RED) : DrawText("Space is up", 10, 10, 20, RED);
    event->getBool(2) ? DrawText("A is down", 10, 30, 20, RED) : DrawText("A is up", 10, 30, 20, RED);
    event->getBool(3) ? DrawText("1 is down", 10, 50, 20, RED) : DrawText("1 is up", 10, 50, 20, RED);
    event->getBool(4) ? DrawText("2 is down", 10, 70, 20, RED) : DrawText("2 is up", 10, 70, 20, RED);
    event->getBool(5) ? DrawText("3 is down", 10, 90, 20, RED) : DrawText("3 is up", 10, 90, 20, RED);
    event->getBool(6) ? DrawText("4 is down", 10, 110, 20, RED) : DrawText("4 is up", 10, 110, 20, RED);
    event->getBool(7) ? DrawText("5 is down", 10, 130, 20, RED) : DrawText("5 is up", 10, 130, 20, RED);
    event->getBool(8) ? DrawText("6 is down", 10, 150, 20, RED) : DrawText("6 is up", 10, 150, 20, RED);
    event->getBool(9) ? DrawText("7 is down", 10, 170, 20, RED) : DrawText("7 is up", 10, 170, 20, RED);
    event->getBool(10) ? DrawText("8 is down", 10, 190, 20, RED) : DrawText("8 is up", 10, 190, 20, RED);
    event->getBool(11) ? DrawText("9 is down", 10, 210, 20, RED) : DrawText("9 is up", 10, 210, 20, RED);
    event->getBool(12) ? DrawText("0 is down", 10, 230, 20, RED) : DrawText("0 is up", 10, 230, 20, RED);
    event->getBool(13) ? DrawText("\" is down", 10, 250, 20, RED) : DrawText("\" is up", 10, 250, 20, RED);
    event->getBool(14) ? DrawText("' is down", 10, 270, 20, RED) : DrawText("' is up", 10, 270, 20, RED);
    

    DrawTextEx(font, message, msgPos, fontSize, msgSpacing, RED);    
    EndDrawing();
  }
  // Cleanup
  CloseWindow();
}