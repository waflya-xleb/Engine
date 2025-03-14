#pragma once
#ifndef _VK_HPP_
#define _VK_HPP_

#include <utils/utils.hpp>
#include "vkUtils/vkUtils.hpp"

#define VK_DEBUG_notifications_
#define VK_DEBUG_L1_
#define VK_DEBUG_L2_

class Vulkan {
	public:
		void run();
		void terminate();

	private:
		VkInstance instance;
		VkPhysicalDeviceProperties physicalDevice;

		void createInstance();
		void createPhysicalDevice();

};

#endif
