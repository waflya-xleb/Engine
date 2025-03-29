#include "temporary.hpp"


void TickFunction( const int tick_per_second, void(*fooPointer)( int a , int b ) ) {
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	std::chrono::duration<float> duration2;
	typedef std::chrono::milliseconds ms;
	int current_tick = 0;
	while (true) {
		duration = su::timer_end( start );
		//if ( current_tick > 1) {
//			std::cout << BLUE << "total tick time: " << duration << "\n" << RESET;
		//	std::cout << BLUE << "time: " << std::chrono::duration_cast<ms>( duration ) << "\n" << RESET;
		//}
		start = su::timer_start();

		fooPointer( 3, 3 );
		current_tick++;
//		if ( current_tick == 10 ) {
//			std::this_thread::sleep_for( std::chrono::milliseconds( 1234 ) );
//		} else {
//			std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
//		}

		duration = su::timer_end( start );
		//std::cout << BLUE << "excess: " << std::chrono::duration_cast<ms>( duration ) << " | " << RESET;
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
	}
}

void wery_hard_math_function( su::Voxel vx[], const float g ) {
	vx[0].xyz[0] -= g;
	vx[1].xyz[0] += g;

	//std::cout << RESET << "\tvx0 X : " << vx[0].xyz[0] << "\n";
	//std::cout << RESET << "\tvx1 X : " << vx[1].xyz[0] << "\n";
}

void math_thread_function( su::Voxel voxels[], const int tick_per_second ) {
	std::cout << MAGNETA << "started.\tMATH THREAD\n" << RESET;
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	typedef std::chrono::milliseconds ms;
	//int i = 0;
	while (true) {
		duration = su::timer_end( start );
		start = su::timer_start();

		//i++;
		wery_hard_math_function( voxels, 0.1f );

		duration = su::timer_end( start );
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
	}
}
