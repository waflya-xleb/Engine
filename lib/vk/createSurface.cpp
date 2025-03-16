#include "vk.hpp"

void Vulkan::createSurface( GLFWwindow* window ) {
	if ( glfwCreateWindowSurface( instance, window, nullptr, &surface ) != VK_SUCCESS ) {
		throw std::runtime_error("failed to create glfw surface.");
	}
#ifdef VK_DEBUG_notifications_
	std::cout << GREEN << "surface create success!\n" << RESET;
#endif
}
