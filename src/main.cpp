#include "engine/engine.hpp"
#include "temporary.hpp"

//#define NDEBUG
#define ACTION_LOG

int main( uint16_t argc, const char* argv[] ) {
	if ( argc > 1 ) su::arg_function( argc, argv );

	auto start = su::timer_start();
	std::chrono::duration<float> program_time;
#ifndef NDEBUG
	std::cout << ITALIC << BLUE << "The September 21st Incident of Gigi Murin. (the start message*)\n" << RESET;
#endif
	const std::string err_log_path = "err_log.txt";
	su::warning_struct warning_list;
	std::string error_text;

	try {
		//throw su::custom_exception( "just error", "the custom exception.", 25 );
		//throw std::runtime_error("the error.");
		Engine engine;
		engine.start();

		engine.end();

	} catch( su::custom_exception& ex ) {
		error_text = "type: " + ex.getType() + "\nmsg: " + ex.getMsg() + "\ncode: " + std::to_string(ex.getCode());

		su::error_log_save( err_log_path, warning_list, error_text, su::timer_end( start ) );
		std::cout << RED << "su::custom_exception\n" << "\ttype: " << ex.getType() << "\n\t" << ex.getMsg() << "\n\t" << ex.getCode() << "\n" << RESET;
		exit( -1 );

	} catch( std::exception& ex ) {
		su::error_log_save( err_log_path, warning_list, "std::exception: " + (std::string)ex.what(), su::timer_end( start ) );
		std::cout << RED << "std::exception: " << ex.what() << "\n" << RESET;
		exit( -1 );

	} catch( ... ) {
		su::error_log_save( err_log_path, warning_list, "unknown exception.", su::timer_end( start ) );
		std::cout << RED << "unknown exception.\n" << RESET;
		exit( -1 );
	}

	return 0;
}
