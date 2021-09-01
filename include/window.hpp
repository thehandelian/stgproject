#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <iostream>

class Window {
    public:

    Window();
    ~Window();

    private:

    const char *window_name = "stgproject";

    int x_res = 640;
    int y_res = 480;

    SDL_Window *window = nullptr;
    SDL_Surface *screenSurface = nullptr;
};

#endif