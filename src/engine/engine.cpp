#include "engine.hpp"

void Engine::start() {
	auto start = su::timer_start();
	createDirs();

	su::action_log_save( "logs/action_log.txt", "===== New program session. =====", true );

	createWindow( WIDTH, HEIGHT );
	std::thread th_init_vk([&]() { initVulkan(); });
	th_init_vk.join();
	std::cout << RESET << "engine init time : " << su::timer_end( start ) << "\n";

	std::thread th_mainloop( [&]() { mainLoop( 144 ); });
	th_mainloop.join();
}


void Engine::end() {
	glfwDestroyWindow( window );
	vulkan.terminate();
	glfwTerminate();
}
