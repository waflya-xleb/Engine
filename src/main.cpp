#include <vk_interface/vk.hpp>
#include "temporary.hpp"

//#define NDEBUG
#define ACTION_LOG

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

#ifdef ACTION_LOG
	su::log_save_new( "log_new.txt", "============ New program session ============", true );
	su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "starting program", "", su::timer_end( start ) );
#endif

	try {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        	GLFWwindow* window = glfwCreateWindow( 1080, 720, "vk engine", nullptr, nullptr );
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "glfw window create", "", su::timer_end( start ) );
#endif

		Vulkan vulkan;
		vk_param param;
		param.enableValidationLayers = true;
		param.validationLayers = { "VK_LAYER_KHRONOS_validation" };
		param.window = window;

		std::thread th_init_vk([&]() { vulkan.run( param ); });
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "started vulkan.run()", "", su::timer_end( start ) );
#endif


		//throw su::custom_exception( "just error", "the custom exception.", 25 );
		//throw std::runtime_error("the error.");

		//su::Voxel voxel[2] = { { 10, 10, 10 }, { -10, -10, -10 } };
		//std::thread th_math( math_thread_function, std::ref(voxel), 40 );
		//std::thread th_test([&]() { TickFunction(2, sum); });

		th_init_vk.join();
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "ended vulkan.run()", "Success", su::timer_end( start ) );
#endif

		std::cout << "init time : " << su::timer_end( start ) << "\n";

#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "starting mainloop", "", su::timer_end( start ) );
#endif
		while ( !glfwWindowShouldClose( window ) ) {
			//std::this_thread::sleep_for( std::chrono::milliseconds( 4000 ) );
			su::terminal();
			break;
			//std::cout << "yaaapi\n";
			glfwPollEvents();
        	}
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "ended mainloop", "Success", su::timer_end( start ) );
#endif
	//	th_math.join();
	//	th_test.join();

		glfwDestroyWindow( window );
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "destroy glfw window", "Success", su::timer_end( start ) );
#endif

		vulkan.terminate();
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "terminate vulkan", "Success", su::timer_end( start ) );
#endif

		glfwTerminate();
#ifdef ACTION_LOG
		su::log_save_new( "log_new.txt", "M", 0, "main.cpp", "terminate glfw", "Success", su::timer_end( start ) );
#endif

		su::log_save( log_path, warning_list, "no fatal errors.", su::timer_end( start ) );


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
