#include <vk_interface/vk.hpp>
#include "temporary.hpp"
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

	//su::log_save_new( "log_new.txt", "============ New program session ============", true );
	//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "starting program", "", su::timer_end( start ) );

	try {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        	GLFWwindow* window = glfwCreateWindow( 1080, 720, "vk engine", nullptr, nullptr );
		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "glfw window create", "", su::timer_end( start ) );

		Vulkan vulkan;
		vk_param param;
		param.enableValidationLayers = true;
		param.validationLayers = { "VK_LAYER_KHRONOS_validation" };
		param.window = window;

		std::thread th_init_vk([&]() { vulkan.run( param ); });
		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "started vulkan.run()", "", su::timer_end( start ) );

		int sum_result = 0;
		if ( !if_sum( 30, 13, sum_result, warning_list ) ) {
			std::cout << sum_result << " <---sum_result\n";
		} else {
			warning_list.warning.push_back( "function 'sum' in 'test' library failure. --- main.cpp" );
			std::cout << YELLOW << "warning: " << warning_list.warning.back() << "\n";
		}

		//throw su::custom_exception( "just error", "the custom exception.", 25 );
		//throw std::runtime_error("the error.");

		//su::Voxel voxel[2] = { { 10, 10, 10 }, { -10, -10, -10 } };
		//std::thread th_math( math_thread_function, std::ref(voxel), 40 );

		th_init_vk.join();
		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "ended vulkan.run()", "Success", su::timer_end( start ) );

		std::cout << "init time : " << su::timer_end( start ) << "\n";

		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "starting mainloop", "", su::timer_end( start ) );
		while ( !glfwWindowShouldClose( window ) ) {
	//		std::this_thread::sleep_for( std::chrono::milliseconds( 4000 ) );

	//		su::write_obj( "map2.obj", voxel );

	//		std::cout << MAGNETA << "\tvx0 X : " << voxel[0].xyz[0] << "\n" << RESET;
	//		std::cout << MAGNETA << "\tvx1 X : " << voxel[1].xyz[0] << "\n" << RESET;
			su::terminal();
			break;
			//std::cout << "yaaapi\n";
			glfwPollEvents();
        	}
	//	th_math.join();

		glfwDestroyWindow( window );
		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "destroy glfw window", "Success", su::timer_end( start ) );

		vulkan.terminate();
		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "terminate vulkan", "Success", su::timer_end( start ) );

		glfwTerminate();
		//su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "terminate glfw", "Success", su::timer_end( start ) );

		//su::log_save( log_path, warning_list, "no fatal errors.", su::timer_end( start ) );


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
