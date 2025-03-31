#include "window.hpp"

void Engine::createWindow( const uint16_t width, const uint16_t height ) {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow( width, height, "vk engine", nullptr, nullptr );
	if ( window == nullptr ) {
		glfwTerminate();
		throw std::runtime_error("failed to create glfw window.");
	}
}
