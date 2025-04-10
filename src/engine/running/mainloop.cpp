#include "../engine.hpp"

void Engine::mainLoop( const int tick_per_second ) {
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	int current_tick = 0;

	while ( !glfwWindowShouldClose( window ) ) {

		duration = su::timer_end( start );
		start = su::timer_start();
		current_tick >= tick_per_second ? current_tick = 0 : current_tick++;

		su::terminal();
		break;
		//std::cout << "yaaapi\n";
		glfwPollEvents();

		duration = su::timer_end( start );
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
        }
}
