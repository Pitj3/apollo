#include <apollo/core/window.h>

int main(int argc, char** argv)
{
	apollo::Window* window = new apollo::Window(1280, 720, "Apollo Game Engine");

	while (!window->shouldClose())
	{
		window->refresh();
	}
}