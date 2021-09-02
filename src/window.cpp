#include <window.hpp>

Window::Window()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
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
        surface = SDL_GetWindowSurface(window);
        
        // Fill the surface white
        SDL_FillRect(surface, nullptr,
                    SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        
        // Update the surface
        SDL_UpdateWindowSurface(window);
}

Window::~Window()
{
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();
}

void Window::display_picture(const char *image_name)
{
    surface = IMG_Load(image_name);

    if (surface == nullptr) {
        std::cerr << "Unable to load image " << image_name << '\n' << IMG_GetError() << '\n';
        exit(1);
    }

    SDL_BlitSurface(surface, nullptr, surface, nullptr);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
}