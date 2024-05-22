/**
 * @file test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */


int main(void) { 
    InitWindow(400, 224, "Template-4.0.0");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
    
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
