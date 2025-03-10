#include "vk.hpp"

void Vulkan::terminate() {
	vkDestroyInstance(instance, nullptr);
#ifdef VK_DEBUG_notifications_
	std::cout << FCYN( "vk terminate\n" );
#endif
}
