#include "vk.hpp"

void Vulkan::terminate() {
	vkDestroyInstance(instance, nullptr);
#ifndef VK_NDEBUG_
	std::cout << FCYN( "vk terminate\n" );
#endif
}
