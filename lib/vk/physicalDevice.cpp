#include "vk.hpp"

void Vulkan::createPhysicalDevice() {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices( instance, &deviceCount, nullptr );
	std::vector <VkPhysicalDevice> devices( deviceCount );
	vkEnumeratePhysicalDevices( instance, &deviceCount, devices.data() );

	vkGetPhysicalDeviceProperties( devices.data()[0], &physicalDevice );
	std::cout << "Device name: " << physicalDevice.deviceName << "\n\n";
}
