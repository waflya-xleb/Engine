#include "vk.hpp"

void Vulkan::terminate() {
	vkDestroyInstance(instance, nullptr);
	std::cout << "vk terminate\n";
}
