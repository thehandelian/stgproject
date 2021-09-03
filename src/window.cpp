#include <window.hpp>

Window::Window()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialise: " << SDL_GetError() << '\n';
        exit(1);
    } 

    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, x_res, y_res, SDL_WINDOW_OPENGL);

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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

void Window::display_picture(const char *image_name)
{
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "SDL2_image initialisation failed: " << IMG_GetError() << '\n';
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Unable to create renderer: " << SDL_GetError() << '\n';
    }

    surface = IMG_Load(image_name);
    if (surface == nullptr) {
        std::cerr << "Unable to load image " << image_name << '\n' << IMG_GetError() << '\n';
        exit(1);
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cerr << "Unable to create texture: " << SDL_GetError() << '\n';
    }

    SDL_FreeSurface(surface);

    for (;;) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture);
    }
}