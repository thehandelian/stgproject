#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

SDL_Window *main_window = nullptr;
SDL_Surface *main_surface = nullptr;
SDL_Surface *png_surface = nullptr;

const int screen_width = 640;
const int screen_height = 480;

bool sdl_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialisation failed: " << SDL_GetError() << '\n';
        return false;
    }

    main_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, screen_width,
                                   screen_height, SDL_WINDOW_SHOWN);
    if (main_window == nullptr) {
        std::cerr << "SDL failed to create window: " << SDL_GetError() << '\n';
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "SDL_image failed to initialise: " << IMG_GetError()
                  << '\n';
        return false;
    }

    main_surface = SDL_GetWindowSurface(main_window);
    if (main_surface == nullptr) {
        std::cerr << "SDL failed to create surface: " << SDL_GetError() << '\n';
        return false;
    } else {
        return true;
    }
}

SDL_Surface *load_surface(std::string img_path)
{
    SDL_Surface *optimised_surface = nullptr;

    SDL_Surface *loaded_surface = IMG_Load(img_path.c_str());
    if (loaded_surface == nullptr) {
        std::cerr << "Unable to load image " << img_path << ": "
                  << IMG_GetError() << '\n';
        return nullptr;
    }

    optimised_surface = SDL_ConvertSurface(loaded_surface, main_surface->format, 0);
    SDL_FreeSurface(loaded_surface);
    if (optimised_surface == nullptr) {
        std::cerr << "Unable to optimise image " << img_path << ": "
                  << IMG_GetError() << '\n';
        return nullptr;
    } else {
        return optimised_surface;
    }
}

void close()
{
	SDL_FreeSurface(png_surface);
	SDL_DestroyWindow(main_window);
	IMG_Quit();
	SDL_Quit();
}


bool load_media()
{
	png_surface = load_surface("testimg.png");
	if (png_surface == nullptr) {
		std::cerr << "loading media failed\n";
		return false;
	} else {
		return true;
	}
}

int main()
{
    if (!sdl_init()) {
        std::cerr << "sdl_init() failed\n";
        return 1;
    } else {
		std::cerr << "sdl_init() success!\n";
    }

	if (!load_media()) {
		std::cerr << "load_media() failed\n";
		return 1;
	} else {
		std::cerr << "load_media() success!\n";
	}

	SDL_Event e;

	for (;;) {
		while(SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				close();
				return(0);
			}
		}

		SDL_BlitSurface(png_surface, nullptr, main_surface, nullptr);
		SDL_UpdateWindowSurface(main_window);
	}

	close();
}