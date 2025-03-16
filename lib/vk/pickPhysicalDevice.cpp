#include "vk.hpp"

void Vulkan::pickPhysicalDevice() {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices( instance, &deviceCount, nullptr );
	
	if ( !deviceCount ) {
		throw std::runtime_error("failed to find GPUs with Vulkan support.");
	}
	std::vector <VkPhysicalDevice> devices( deviceCount );
	vkEnumeratePhysicalDevices( instance, &deviceCount, devices.data() );

	physicalDevice = devices.data()[0];
	std::cout << GREEN << "pick physicalDevice success!\n" << RESET;
}
