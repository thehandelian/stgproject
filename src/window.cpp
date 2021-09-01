#include <window.hpp>

Window::Window()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialise: " << SDL_GetError() << '\n';
        exit(1);
    } 

    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, x_res, y_res, SDL_WINDOW_SHOWN);

        if (window == nullptr) {
            std::cerr << "Window could not be created: " << SDL_GetError() << '\n';
            exit(1);
        } 

        // Get window surface
        screenSurface = SDL_GetWindowSurface(window);
        
        // Fill the surface white
        SDL_FillRect(screenSurface, nullptr,
                    SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
        
        // Update the surface
        SDL_UpdateWindowSurface(window);
        
        // Wait two seconds
        SDL_Delay(2000);
}

Window::~Window()
{
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();
}