#include "engine.hpp"

void Engine::start() {
	auto start = su::timer_start();
	mkdir( "logs", 0777) == 0 ? std::cout << GREEN << "'logs' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'logs' dir\n" << RESET;
	mkdir( "scripts", 0777) == 0 ? std::cout << GREEN << "'scripts' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'scripts' dir\n" << RESET;

	createWindow( WIDTH, HEIGHT );
	std::thread th_init_vk([&]() { initVulkan(); });
	th_init_vk.join();
	std::cout << RESET << "engine init time : " << su::timer_end( start ) << "\n";
	mainLoop();
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
	glfwDestroyWindow( window );
	vulkan.terminate();
	glfwTerminate();
}
