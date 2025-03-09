#include "utils/utils.hpp"
#include <vk/vk.hpp>
extern "C" {
#include "test.h"
}

bool if_sum( int a, int b, int &return_value ) {
	try {
		return_value = sum( a, b );
		return 0;
	} catch(...) {
		return 1;
	}
}

//#define NDEBUG

int i = 0;
int j = 0;
int k = 0;
std::string ch = "";

int main( int argc, const char* argv[] ) {
	if ( argc > 1 ) {
		su::arg_function( argc, argv );
	}

	auto start = su::timer_start();
#ifndef NDEBUG
	std::cout << FBLU("The September 21st Incident of Gigi Murin. (the start message*)\n");
#endif
	std::string log_path = "log.txt";
	std::string log_text = "the custom text";
	std::string error_text;
	std::chrono::duration<float> program_time;

	try {
		Vulkan vulkan;

		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        	GLFWwindow* window = glfwCreateWindow(100, 200, "Vulkan", nullptr, nullptr);

		vulkan.run();

		int sum_result = 0;
		if ( !if_sum(2147483648, 13, sum_result) ) {
			std::cout << sum_result << " <---sum_result\n";
		} else {
			std::cout << FYEL("warning: sum failure.\n");
		}

		//throw su::custom_exception( "just error", "the custom exception.", 25 );
		//throw std::runtime_error("the error.");

		while (!glfwWindowShouldClose(window)) {
			i++;
			if ( i == 10000 ) {
				i = 0;
				j++;
			}
			if ( j == 100 ) {
				j = 0;
				std::cout << "yaaapi\n";
				std::cin >> ch;
				if ( ch == "exit" ) {
					break;
				}
			}
			glfwPollEvents();
        	}

		glfwDestroyWindow( window );

		vulkan.terminate();

		glfwTerminate();

		program_time = su::timer_end( start );
		log_text = "program end are success!";
		error_text = "no errors";
		su::log_save( log_path, log_text, error_text, program_time );


	} catch( su::custom_exception& ex ) {

		std::cout << FRED("su::custom_exception\n");
		std::cout << FRED("type: " << ex.getType() << "\n");
		std::cout << FRED("msg: " << ex.getMsg() << "\n");
		std::cout << FRED("code: " << ex.getCode() << "\n");

		program_time = su::timer_end( start );
		log_text = "the program has stopped.";
		error_text = "type: " + ex.getType() + "\nmsg: " + ex.getMsg() + "\ncode: " + std::to_string(ex.getCode());

		su::log_save( log_path, log_text, error_text, program_time );
		exit( -1 );

	} catch( std::exception& ex ) {

		std::cout << FRED("std::exception: " << ex.what() << "\n");
		
		program_time = su::timer_end( start );
		log_text = "tre program has stopped.";
		error_text = "std::exception: " + ( std::string )ex.what();
		su::log_save( log_path, log_text, error_text, program_time );
		exit( -1 );

	} catch( ... ) {

		std::cout << FRED("unknown exception.\n");
		log_text = "the program has stopped.";
		error_text = "unknown exception.";
		program_time = su::timer_end( start );
		su::log_save( log_path, log_text, error_text, program_time );
		exit( -1 );
	}

	return 0;
}
