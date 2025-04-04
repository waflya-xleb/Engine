#include "engine.hpp"

void Engine::start() {
	auto start = su::timer_start();
	mkdir( "logs", 0777) == 0 ? std::cout << GREEN << "'logs' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'logs' dir\n" << RESET;
	mkdir( "scripts", 0777) == 0 ? std::cout << GREEN << "'scripts' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'scripts' dir\n" << RESET;

	su::action_log_save( "logs/action_log.txt", "===== New program session. =====", true );

	createWindow( WIDTH, HEIGHT );
	std::thread th_init_vk([&]() { initVulkan(); });
	th_init_vk.join();
	std::cout << RESET << "engine init time : " << su::timer_end( start ) << "\n";

	std::thread th_mainloop( [&]() { mainLoop( 144 ); });
	th_mainloop.join();
}

void Engine::initVulkan() {
	param.enableValidationLayers = true;
	param.validationLayers = { "VK_LAYER_KHRONOS_validation" };
	param.window = window;

	vulkan.run( param );

	//std::thread th_init_vk([&]() { vulkan.run( param ); });
}

void Engine::mainLoop( const int tick_per_second ) {
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	int current_tick = 0;

	while ( !glfwWindowShouldClose( window ) ) {

		duration = su::timer_end( start );
		start = su::timer_start();
		current_tick >= tick_per_second ? current_tick = 0 : current_tick++;

		//su::terminal();
		//break;
		std::cout << "yaaapi\n";
		glfwPollEvents();

		duration = su::timer_end( start );
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
        }
}

void Engine::end() {
	glfwDestroyWindow( window );
	vulkan.terminate();
	glfwTerminate();
}
