#include "vk.hpp"

bool Vulkan::createInstance( su::warning_struct &warning_list ) {
	try {
		VkApplicationInfo appInfo{};
        	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        	appInfo.pApplicationName = "";
        	appInfo.applicationVersion = 0;
        	appInfo.pEngineName = "";
        	appInfo.engineVersion = 0;
        	appInfo.apiVersion = VK_API_VERSION_1_4;

        	VkInstanceCreateInfo createInfo{};
        	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        	createInfo.pApplicationInfo = &appInfo;

 	       	uint32_t glfwExtensionCount = 0;
        	const char** glfwExtensions;
        	glfwExtensions = glfwGetRequiredInstanceExtensions( &glfwExtensionCount );

        	createInfo.enabledExtensionCount = glfwExtensionCount;
        	createInfo.ppEnabledExtensionNames = glfwExtensions;

        	std::vector<const char*> validationLayers = {
        		//"VK_LAYER_LUNARG_object_tracker"
			"VK_LAYER_KHRONOS_validation"
        		//"VK_LAYER_LUNARG_api_dump"
			//"VK_LAYER_LUNARG_monitor"
    		};

		createInfo.enabledLayerCount = static_cast<uint32_t>( validationLayers.size() );
        	createInfo.ppEnabledLayerNames = validationLayers.data();

        	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
			warning_list.warning_L2.push_back( "failed to create instance in function 'createInstance' in 'vk_interface' library. --- createInstance.cpp" );
			return 1;
        	}

		return 0;
	} catch(...) {
		warning_list.warning_L2.push_back( "unknown error in function 'createInstance' in 'vk_interface' library. --- creaeInstance.cpp" );
		return 1;
	}
}
