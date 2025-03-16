#include "vk.hpp"

void Vulkan::terminate() {
	vkDestroySurfaceKHR(instance, surface, nullptr);
	vkDestroyInstance(instance, nullptr);
#ifdef VK_DEBUG_notifications_
	std::cout << CYAN << "vk terminate\n";
#endif
}
