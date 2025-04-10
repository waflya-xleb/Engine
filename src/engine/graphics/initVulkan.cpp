#include "../engine.hpp"

void Engine::initVulkan() {
	param.enableValidationLayers = true;
	param.validationLayers = { "VK_LAYER_KHRONOS_validation" };
	param.window = window;

	vulkan.run( param );

	//std::thread th_init_vk([&]() { vulkan.run( param ); });
}
