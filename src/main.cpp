#include <iostream>
#include <window.hpp>

int main()
{
    std::cerr << "making a window" << '\n';
    Window main_window;

	std::cerr << "showing picture" << '\n';
	
	main_window.display_picture("testimg.bmp");
    std::cerr << "returning from main()" << '\n';
}