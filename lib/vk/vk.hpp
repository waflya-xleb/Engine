#pragma once
#ifndef _VK_HPP_
#define _VK_HPP_

#include "utils/vkUtils.hpp"

class Vulkan {
	public:
		void run();
		void terminate();
	
	private:
		VkInstance instance;

		void createInstance();

};

#endif
