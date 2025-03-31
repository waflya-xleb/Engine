#include "temporary.hpp"

bool if_sum( const int a, const int b, int &return_value, su::warning_struct &warning_list ) {
	try {
		if ( a <= 1073741823 && b <= 1073741823 ) {
			return_value = sum( a, b );
			return 0;
		}
		warning_list.warning_L2.push_back( "max input value for function 'sum' exceeded in 'test' library. --- main.cpp" );
		return 1;
	} catch(...) {
		warning_list.warning_L2.push_back( "unknown error in function 'sum' in 'test' library. --- main.cpp" );
		return 1;
	}
}

/*
void TickFunction( const int tick_per_second, int(*fooPointer)( int a , int b ) ) {
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	std::chrono::duration<float> duration2;
	typedef std::chrono::milliseconds ms;
	int current_tick = 0;
	while (true) {
		duration = su::timer_end( start );
		(current_tick > 1) ? (std::cout << BLUE << "time: " << std::chrono::duration_cast<ms>( duration ) << "\n" << RESET) : std::cout << "";
		start = su::timer_start();

		current_tick++;
		fooPointer( 3, 3 );

		duration = su::timer_end( start );
		std::cout << BLUE << "excess: " << std::chrono::duration_cast<ms>( duration ) << " | " << RESET;
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
	}
}

void wery_hard_math_function( su::Voxel vx[], const float g ) {
	vx[0].xyz[0] -= g;
	vx[1].xyz[0] += g;
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
*/
