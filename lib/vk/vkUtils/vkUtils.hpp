#pragma once
#ifndef _VK_UTILS_
#define _VK_UTILS_

#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"
#include <utils/utils.hpp>

namespace vk {
	namespace su {
		bool checkValidationLayerSupport( std::vector< const char* > requestedLayers, std::vector< const char* > &unavailableLayers );
	}// su namespace
}// vk namespace

#endif
