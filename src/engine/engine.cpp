#include "engine.hpp"

void Engine::start() {
	std::cout << a << " ENGINE\n";
	if ( mkdir( "logs", 0777) == 0 ) {
		std::cout << GREEN << "'logs' dir create success!\n" << RESET;
	} else {
		std::cout << YELLOW << "failed to create 'logs' dir\n" << RESET;
	}

	std::cout << "createWindow start\n";
	createWindow();
	std::cout << "createWindow end\n";
	std::cout << "vk thread start\n";
	std::thread th_init_vk([&]() { initVulkan(); });
	th_init_vk.join();
	std::cout << "vk thread end\n";
	std::cout << "mainLoop start\n";
	mainLoop();
	std::cout << "mainLoop end\n";
}

void Engine::createWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow( 1080, 720, "vk engine", nullptr, nullptr );
}

void Engine::initVulkan() {
	param.enableValidationLayers = true;
	param.validationLayers = { "VK_LAYER_KHRONOS_validation" };
	param.window = window;

	vulkan.run( param );

	//std::thread th_init_vk([&]() { vulkan.run( param ); });
}

void Engine::mainLoop() {
	while ( !glfwWindowShouldClose( window ) ) {
		//std::this_thread::sleep_for( std::chrono::milliseconds( 4000 ) );
		su::terminal();
		break;
		//std::cout << "yaaapi\n";
		glfwPollEvents();
        }
}

void Engine::end() {
	std::cout << "END ENGINE\n";
	glfwDestroyWindow( window );
	vulkan.terminate();
	glfwTerminate();
}
