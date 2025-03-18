#pragma once
#ifndef _VK_HPP_
#define _VK_HPP_

#include "vkUtils/vkUtils.hpp"

#define VK_DEBUG_notifications_
#define VK_DEBUG_L1_
#define VK_DEBUG_L2_

class Vulkan {
	public:
		void run( GLFWwindow* window );
		void terminate();

	private:
		VkInstance instance;
		VkSurfaceKHR surface;
		VkPhysicalDevice physicalDevice;
		VkDevice device;
		VkQueue queue;

		void createInstance();
		void createSurface( GLFWwindow* window );
		void pickPhysicalDevice();
		void createLogicalDevice();

};

#endif
