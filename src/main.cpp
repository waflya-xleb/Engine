#include "engine/engine.hpp"
#include "temporary.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//#define NDEBUG
#define ACTION_LOG

int main( uint16_t argc, const char* argv[] ) {
	pid_t pid;
	switch(pid=fork()) {
	case -1:
		perror("fork"); /* произошла ошибка */
		exit(1); /*выход из родительского процесса*/
	case 0:
		std::cout << " MAIN CHILD: PID " << getpid() << " : PARENT PID " << getppid() << "\n";
		std::cout << GRAY << "процесс запущенный main запускает шарманку.." << RESET << "\n";
		int return_value;
		return_value = execl("test_program"," ","Hello_World!", NULL);
		exit(return_value);
	default:
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
			std::cout << "\033[38;2;255;165;0m" << UNDERLINE << "Text\033[0m\n";

			std::cout << "MAIN: PID " << getpid() << " : CHILD: PID " << pid << "\n";
			int status;
			waitpid(pid, &status, 0);
			std::cout << "MAIN: child return value: " << WEXITSTATUS(status) << "\n";
			if (WEXITSTATUS(status) != 0) {
				std::cout << RED << "failed to normal run\n";
			}


    			//std::cout << "\033[?25l";
    			//std::cout << "\033c";
    			//std::cout << "\033[?25h\nDone!\n";
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
	}

	return 0;
}
