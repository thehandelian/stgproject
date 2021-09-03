#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

class Window {
   public:
    Window();
    ~Window();

    void display_picture(const char *image_name);

   private:
    const char *window_name = "stgproject";

    int x_res = 640;
    int y_res = 480;

    SDL_Window *window = nullptr;
    SDL_Surface *surface = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif