#include "utils/utils.hpp"
#include <GLFW/glfw3.h>
#include "vk/vk.hpp"

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
	std::cout << "The September 21st Incident of Gigi Murin. (the start message*)\n";
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

		throw su::custom_exception( "not fatal", "the custom exception.", 25 );
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
		su::log_save( log_path, log_text, program_time );


	} catch( su::custom_exception& ex ) {

		std::cout << "su::custom_exception\n";
		std::cout << "type: " << ex.getType() << "\n";
		std::cout << "msg: " << ex.getMsg() << "\n";
		std::cout << "code: " << ex.getCode() << "\n";

		program_time = su::timer_end( start );
		error_text = "type: " + ex.getType() + "\nmsg: " + ex.getMsg() + "\ncode: " + std::to_string(ex.getCode());

		if ( ex.getType() == "not fatal" ) {	
			su::error_log_save( log_path, log_text, error_text, program_time );
		}
		if ( ex.getType() == "fatal" ) {
			log_text = "the program has stopped, su::custom_exception";
			su::error_log_save( log_path, log_text, error_text, program_time );
			exit( -1 );
		}

	} catch( std::exception& ex ) {

		std::cout << "std::exception: " << ex.what() << "\n";
		program_time = su::timer_end( start );
		error_text = "the program has stopped, std::exception: " + ( std::string )ex.what();
		su::error_log_save( log_path, log_text, error_text, program_time );
		exit( -1 );

	} catch( ... ) {

		std::cout << "unknown exception.\n";
		error_text = "the program has stopped, unknown error.";
		program_time = su::timer_end( start );
		su::error_log_save( log_path, log_text, error_text, program_time );
		exit( -1 );
	}

	return 0;
}
