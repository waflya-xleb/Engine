#include <vk/vk.hpp>
extern "C" {
#include "test.h"
}

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

// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================
//class Voxel {
//	public:
//		double xyz[3] = {0, 0, 0};
//		float rotate[3] = {0, 0, 0};
//		float scale = 1.0f;
//
//		uint8_t rgb[3] = {40, 40, 40};
//		float alpha = 1.0;
//		uint8_t glow = 0;
//
//		uint16_t durability = 65000;
//		uint8_t bondability = 0;
//		bool stationary = false;
//
//		uint16_t temperature = 0;
//		uint8_t gravity = 255;
//		uint8_t mass = 1;
//		uint8_t density = 1;
//		uint8_t id = 0;
//
//		//uint16_t chunk_index = 0;
//	private:
//};
// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================


void TickFunction() {
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	std::chrono::duration<float> duration2;
	typedef std::chrono::milliseconds ms;
	int tick_per_second = 2;
	int i = 0;
	while (true) {
		duration = su::timer_end( start );
		if ( i > 1) {
			//std::cout << BLUE << "total tick time: " << duration << "\n" << RESET;
			std::cout << BLUE << "time: " << std::chrono::duration_cast<ms>( duration ) << "\n" << RESET;
		}
		start = su::timer_start();

		i++;
		if ( i == 10 ) {
			std::this_thread::sleep_for( std::chrono::milliseconds( 1234 ) );
		} else {
			std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
		}

		duration = su::timer_end( start );
		std::cout << BLUE << "excess: " << std::chrono::duration_cast<ms>( duration ) << " | " << RESET;
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
	}
}

void wery_hard_math_function( su::Voxel vx[], const int g ) {
	//double x1 = 0, x2 = 20;
	//vx[0].xyz[0] = 0.0;

	//vx[1].xyz[0] = 20.0;
	if ( vx[0].xyz[0] < (vx[1].xyz[0] + 1) && vx[0].xyz[0] > (vx[1].xyz[0] - 1) ) {
	} else {
		if ( vx[0].xyz[0] > vx[1].xyz[0] ) {
			vx[0].xyz[0] -= 0.01;
		}
		if ( vx[0].xyz[0] < vx[1].xyz[0] ) {
			vx[0].xyz[0] += 0.01;
		}
	}

	if ( vx[0].xyz[1] < (vx[1].xyz[1] + 1) && vx[0].xyz[1] > (vx[1].xyz[1] - 1) ) {
	} else {
		if ( vx[0].xyz[1] > vx[1].xyz[1] ) {
			vx[0].xyz[1] -= 0.01;
		}
		if ( vx[0].xyz[1] < vx[1].xyz[1] ) {
			vx[0].xyz[1] += 0.01;
		}
	}

	if ( vx[0].xyz[2] < (vx[1].xyz[2] + 1) && vx[0].xyz[2] > (vx[1].xyz[2] - 1) ) {
	} else {
		if ( vx[0].xyz[2] > vx[1].xyz[2] ) {
			vx[0].xyz[2] -= 0.01;
		}
		if ( vx[0].xyz[2] < vx[1].xyz[2] ) {
			vx[0].xyz[2] += 0.01;
		}
	}



	if ( vx[1].xyz[0] < (vx[0].xyz[0] + 1) && vx[1].xyz[0] > (vx[0].xyz[0] - 1) ) {
	} else {
		if ( vx[1].xyz[0] > vx[0].xyz[0] ) {
			vx[1].xyz[0] -= 0.01;
		}
		if ( vx[1].xyz[0] < vx[0].xyz[0] ) {
			vx[1].xyz[0] += 0.01;
		}
	}

	//std::cout << RESET << "\tvx0 X : " << vx[0].xyz[0] << "\n";
	//std::cout << RESET << "\tvx1 X : " << vx[1].xyz[0] << "\n";
}

void math_thread_function( su::Voxel voxels[], const int tick_per_second ) {
	std::cout << MAGNETA << "started.\tMATH THREAD\n" << RESET;
	auto start = su::timer_start();
	std::chrono::duration<float> duration;
	typedef std::chrono::milliseconds ms;
	//int i = 0;
	int g = 1;
	while (true) {
		duration = su::timer_end( start );
		start = su::timer_start();

		//i++;
		wery_hard_math_function( voxels, g );

		duration = su::timer_end( start );
		std::this_thread::sleep_for( std::chrono::milliseconds( static_cast<ms>( 1000 / tick_per_second ) - std::chrono::duration_cast<ms>( duration ) ) );
	}
}

//#define NDEBUG

int main( uint16_t argc, const char* argv[] ) {
	if ( argc > 1 ) {
		su::arg_function( argc, argv );
	}

	auto start = su::timer_start();
#ifndef NDEBUG
	std::cout << ITALIC << BLUE << "The September 21st Incident of Gigi Murin. (the start message*)\n" << RESET;
#endif
	const std::string log_path = "log.txt";
	su::warning_struct warning_list;
	std::string error_text;
	std::chrono::duration<float> program_time;

	try {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        	GLFWwindow* window = glfwCreateWindow( 1080, 720, "vk engine", nullptr, nullptr );

		Vulkan vulkan;

		std::thread th_init_vk([&]() {
				vulkan.run( window );
				});

		//vulkan.run( window );

		int sum_result = 0;
		if ( !if_sum( 30, 13, sum_result, warning_list ) ) {
			std::cout << sum_result << " <---sum_result\n";
		} else {
			warning_list.warning.push_back( "function 'sum' in 'test' library failure. --- main.cpp" );
			std::cout << YELLOW << "warning: " << warning_list.warning.back() << "\n";
		}

		//throw su::custom_exception( "just error", "the custom exception.", 25 );
		//throw std::runtime_error("the error.");

		//Voxel voxel;
		//std::cout << sizeof(voxel) << " : voxel\n";
		//std::cout << sizeof(Voxel) << " : Voxel\n";

		//std::thread th( su::terminal );
		su::Voxel voxel[2] = { { 10, 10, 10 }, { -10, -10, -10 } };
		std::thread th_math( math_thread_function, std::ref(voxel), 40 );

		th_init_vk.join();
		std::cout << su::timer_end( start ) << " <---------------------------------------------------------dsflj\n";
		su::write_obj( "map.obj", voxel );
		while ( !glfwWindowShouldClose( window ) ) {
			std::this_thread::sleep_for( std::chrono::milliseconds( 4000 ) );

			su::write_obj( "map2.obj", voxel );

			std::cout << MAGNETA << "MAIN LOOP\n" << RESET;
			std::cout << MAGNETA << "\tvx0 X : " << voxel[0].xyz[0] << "\n" << RESET;
			std::cout << MAGNETA << "\tvx0 Y : " << voxel[0].xyz[1] << "\n" << RESET;
			std::cout << MAGNETA << "\tvx0 Z : " << voxel[0].xyz[2] << "\n" << RESET;

			std::cout << MAGNETA << "\tvx1 X : " << voxel[1].xyz[0] << "\n" << RESET;
			std::cout << MAGNETA << "\tvx1 Y : " << voxel[1].xyz[1] << "\n" << RESET;
			std::cout << MAGNETA << "\tvx1 Z : " << voxel[1].xyz[2] << "\n" << RESET;
			//su::terminal();
			//break;
			//std::cout << "yaaapi\n";
			glfwPollEvents();
        	}
		//th.join();
		th_math.join();

		glfwDestroyWindow( window );

		vulkan.terminate();

		glfwTerminate();

		program_time = su::timer_end( start );
		error_text = "no fatal errors.";
		su::log_save( log_path, warning_list, error_text, program_time );


	} catch( su::custom_exception& ex ) {
		program_time = su::timer_end( start );
		error_text = "type: " + ex.getType() + "\nmsg: " + ex.getMsg() + "\ncode: " + std::to_string(ex.getCode());

		su::error_log_save( log_path, warning_list, error_text, program_time );

		std::cout << RED << "su::custom_exception\n";
		std::cout << RED << "\ttype: " << ex.getType() << "\n";
		std::cout << RED << "\tmsg: " << ex.getMsg() << "\n";
		std::cout << RED << "\tcode: " << ex.getCode() << "\n";

		exit( -1 );

	} catch( std::exception& ex ) {
		program_time = su::timer_end( start );
		error_text = "std::exception: " + ( std::string )ex.what();

		su::error_log_save( log_path, warning_list, error_text, program_time );
		std::cout << RED << "std::exception: " << ex.what() << "\n";

		exit( -1 );

	} catch( ... ) {
		error_text = "unknown exception.";
		program_time = su::timer_end( start );
		su::error_log_save( log_path, warning_list, error_text, program_time );

		std::cout << RED << "unknown exception.\n";
		exit( -1 );
	}

	return 0;
}
