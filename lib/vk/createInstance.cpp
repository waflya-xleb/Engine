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

	//extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

#ifdef VK_DEBUG_notifications_
	std::cout << CYAN << "Vulkan extensions: \n";
	for ( uint32_t i = 0; i < extensions.size(); i++) {
		std::cout << MAGNETA "\t" << extensions[i] << RESET << "\n";
	}
#endif
        createInfo.enabledExtensionCount = static_cast<uint32_t>( extensions.size() );
        createInfo.ppEnabledExtensionNames = extensions.data();

        std::vector<const char*> validationLayers = {
        	//"VK_LAYER_LUNARG_parameter_validation",
        	//"VK_LAYER_LUNARG_device_limits",
        	//"VK_LAYER_LUNARG_object_tracker",
		"VK_LAYER_KHRONOS_validation"
        	//"VK_LAYER_LUNARG_api_dump"
		//"VK_LAYER_LUNARG_monitor"
    	};

#ifdef VK_DEBUG_notifications_
	std::cout << YELLOW << "\nсписок запрошенных слоёв проверки:\n\t" << MAGNETA;
	for ( const char* layerName : validationLayers ) {
		std::cout << layerName << "\n\t";
	}
	std::cout << "\n" << RESET;
#endif

	std::vector < const char* > unavailableLayers;
	if ( !vk::su::checkValidationLayerSupport( validationLayers, unavailableLayers ) ) {

		std::cout << YELLOW << "запрошенные слои проверки недоступны:\n\t" << MAGNETA;
		for ( const char* layer : unavailableLayers ) {
			std::cout << layer << "\n\t";
		}
		std::cout << "\n" << RESET;
		//throw su::custom_exception( "instance support layers error", "validationLayers not present.", 0 );
		throw std::runtime_error("requested layer unavailable");
	}

	createInfo.enabledLayerCount = static_cast<uint32_t>( validationLayers.size() );
        createInfo.ppEnabledLayerNames = validationLayers.data();

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		//throw su::custom_exception( "create instance error", "failed to create instance.", 1 );
		throw std::runtime_error("failed to create instance");
        }
#ifdef VK_DEBUG_notifications_
	std::cout << GREEN << "create instance success!\n" << RESET;
#endif
}
