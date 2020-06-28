#include <apollo/core/window.h>

using namespace apollo;

int main(int argc, char** argv)
{
	Window* window = new Window(1280, 720, "Apollo Game Engine");

	while (!window->shouldClose())
	{
		window->refresh();
	}
}