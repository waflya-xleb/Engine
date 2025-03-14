#include "vk.hpp"

void Vulkan::terminate() {
	vkDestroyInstance(instance, nullptr);
#ifdef VK_DEBUG_notifications_
	std::cout << CYAN << "vk terminate\n";
#endif
}
