#include "vk.hpp"

void Vulkan::createInstance() {
	VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "vk_interface";
        appInfo.applicationVersion = VK_MAKE_VERSION( 0, 0, 1 );
        appInfo.pEngineName = nullptr;
        appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_4;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

 	uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions( &glfwExtensionCount );

	std::vector< const char* > extensions( glfwExtensions, glfwExtensions + glfwExtensionCount );

#ifdef VK_DEBUG_notifications_
	std::cout << FCYN( "Vulkan extensions: \n" );
	for ( uint32_t i = 0; i < extensions.size(); i++) {
		std::cout << FMAG( "\t" << extensions[i] << "\n" );
	}
#endif
        createInfo.enabledExtensionCount = static_cast<uint32_t>( extensions.size() );
        createInfo.ppEnabledExtensionNames = extensions.data();

        std::vector<const char*> validationLayers = {
        	//"VK_LAYER_LUNARG_object_tracker"
		"VK_LAYER_KHRONOS_validation"
        	//"VK_LAYER_LUNARG_api_dump"
		//"VK_LAYER_LUNARG_monitor"
    	};

	createInfo.enabledLayerCount = static_cast<uint32_t>( validationLayers.size() );
        createInfo.ppEnabledLayerNames = validationLayers.data();

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		//throw su::custom_exception( "instance error", "validationLayers not present.", 0 );
		throw std::runtime_error("failed to create instance");
        }
}
