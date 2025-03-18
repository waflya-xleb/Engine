#include "vk.hpp"

// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111
// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111
// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111

void Vulkan::createLogicalDevice() {// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111
	VkDeviceQueueCreateInfo queueCreateInfo = {};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = 0;
	queueCreateInfo.queueCount = 1;
	float queuePriority = 1.0f;
	queueCreateInfo.pQueuePriorities = &queuePriority;

	std::vector< const char* > deviceExtensions = {
		"VK_KHR_swapchain"
	};

	VkDeviceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pQueueCreateInfos = &queueCreateInfo;
	createInfo.queueCreateInfoCount = 1;
	createInfo.ppEnabledExtensionNames = deviceExtensions.data();
	createInfo.enabledExtensionCount = 1;
	createInfo.enabledLayerCount = 0;

	if ( vkCreateDevice( physicalDevice, &createInfo, nullptr, &device ) != VK_SUCCESS ) {
		throw std::runtime_error("failed to create logical device.");
	}
#ifdef VK_DEBUG_notifications_
	std::cout << GREEN << "create logical device success!\n" << RESET;
#endif
	vkGetDeviceQueue( device, 0, 0, &queue );
}

// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111
// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111
// ВНИМАНИЕ! ВНИМАНИЕ! ВНИМАНИЕ!         ФУНКЦИЯ ГОВНО ЕБАНОЕ НА КОСТЫЛЯХ, НАДО БУДЕТ ПЕРЕДЕЛАТЬ!!!!!1!!!!1!11!!1111
