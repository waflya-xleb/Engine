#include "vk.hpp"

void Vulkan::getDeviceName() {
	VkPhysicalDeviceProperties physicalDevice2;
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices( instance, &deviceCount, nullptr );
	std::vector <VkPhysicalDevice> devices( deviceCount );
	vkEnumeratePhysicalDevices( instance, &deviceCount, devices.data() );

	vkGetPhysicalDeviceProperties( devices.data()[0], &physicalDevice2 );
	std::cout << "Device name: " << physicalDevice2.deviceName << "\n\n";
	std::cout << "Device name: " << devices.size() << "\n\n";
}
