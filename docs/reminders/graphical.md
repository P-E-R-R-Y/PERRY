# Graphic

## 3d link

[How to make a 3D Renderer [Explained Simply]](https://youtu.be/nvWDgBGcAIM?si=Jx21AM12tDT1K_W-)
[](https://www.youtube.com/watch?v=9g3RPbRhMaQ)
[](https://www.youtube.com/watch?v=fSjc8vLMg8c)
## fix event

```cpp
if (window->isPoll()) {
                        while (window->pollEvent()) {
                            window->eventClose();
                            this->eventHandler();
                        }
                    } else {
                        window->eventClose();
                        this->eventHandler();
                    }
//Turns to

while (window->pollEvent()) {
    window->eventClose();
    this->eventHandler();
}

// Implementation of pollEvent() in the window class
bool pollEvent() {
    if (isPoll()) {
        // Actual polling logic here
        return true; // Or false when no more events
    }
    // Non-polling logic: ensure it's called once
    static bool hasRun = false;
    if (!hasRun) {
        hasRun = true;
        return true;
    }
    return false;
}
```

## next