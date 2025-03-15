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
	std::string log_text = "the custom text";
	su::warning_struct warning_list;
	std::string error_text;
	std::chrono::duration<float> program_time;

	try {
		Vulkan vulkan;
		bool if_terminate = 1;

		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        	GLFWwindow* window = glfwCreateWindow( 1080, 720, "vk engine", nullptr, nullptr );

		try {
			vulkan.run();

		} catch( std::exception& ex ) {
			if_terminate = 0;
			std::cout << RED << "vulkan failed!\n\t" << "std::exception: " << ex.what() << "\n" << RESET;
		} catch(...) {
			if_terminate = 0;
			std::cout << RED << "vulkan failed!\n\tunknown error.\n" << RESET;
		}

		int sum_result = 0;
		if ( !if_sum( 30, 13, sum_result, warning_list ) ) {
			std::cout << sum_result << " <---sum_result\n";
		} else {
			warning_list.warning.push_back( "function 'sum' in 'test' library failure. --- main.cpp" );
			std::cout << YELLOW << "warning: " << warning_list.warning.back() << "\n";
		}

		//throw su::custom_exception( "just error", "the custom exception.", 25 );
		//throw std::runtime_error("the error.");

		//std::thread th( su::terminal );
		while ( !glfwWindowShouldClose( window ) ) {
			su::terminal();
			break;
			//std::cout << "yaaapi\n";
			glfwPollEvents();
        	}
		//th.join();

		glfwDestroyWindow( window );

		if ( if_terminate ) {
			vulkan.terminate();
		}

		glfwTerminate();

		program_time = su::timer_end( start );
		log_text = "end are success!";
		error_text = "no fatal errors.";
		su::log_save( log_path, log_text, warning_list, error_text, program_time );


	} catch( su::custom_exception& ex ) {
		program_time = su::timer_end( start );
		log_text = "the program has stopped.";
		error_text = "type: " + ex.getType() + "\nmsg: " + ex.getMsg() + "\ncode: " + std::to_string(ex.getCode());

		su::log_save( log_path, log_text, warning_list, error_text, program_time );

		std::cout << RED << "su::custom_exception\n";
		std::cout << RED << "\ttype: " << ex.getType() << "\n";
		std::cout << RED << "\tmsg: " << ex.getMsg() << "\n";
		std::cout << RED << "\tcode: " << ex.getCode() << "\n";

		exit( -1 );

	} catch( std::exception& ex ) {
		program_time = su::timer_end( start );
		log_text = "tre program has stopped.";
		error_text = "std::exception: " + ( std::string )ex.what();

		su::log_save( log_path, log_text, warning_list, error_text, program_time );
		std::cout << RED << "std::exception: " << ex.what() << "\n";

		exit( -1 );

	} catch( ... ) {
		log_text = "the program has stopped.";
		error_text = "unknown exception.";
		program_time = su::timer_end( start );
		su::log_save( log_path, log_text, warning_list, error_text, program_time );

		std::cout << RED << "unknown exception.\n";
		exit( -1 );
	}

	return 0;
}
