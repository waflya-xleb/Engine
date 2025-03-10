#pragma once
#ifndef _VK_HPP_
#define _VK_HPP_

#include <utils/utils.hpp>
#include "vkUtils/vkUtils.hpp"

#define VK_DEBUG_notifications_
#define VK_DEBUG_L2_

class Vulkan {
	public:
		bool run( su::warning_struct &warning_list );
		void terminate();

	private:
		VkInstance instance;

		bool createInstance( su::warning_struct &warning_list );

};

#endif
