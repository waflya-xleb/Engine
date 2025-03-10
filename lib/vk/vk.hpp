#pragma once
#ifndef _VK_HPP_
#define _VK_HPP_

#include "utils/vkUtils.hpp"
#include "utils/utils.hpp"

class Vulkan {
	public:
		bool run( su::warning_struct &warning_list );
		void terminate();

	private:
		VkInstance instance;

		bool createInstance( su::warning_struct &warning_list );

};

#endif
