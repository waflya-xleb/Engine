#include "utils.hpp"

namespace su {
	custom_exception::custom_exception( std::string type, std::string msg, uint32_t code ) {
		this->type = type;
		this->msg = msg;
		this->code = code;
	}// constructor custom_exception

	std::string custom_exception::getType() {
		return type;
	}// getType()

	std::string custom_exception::getMsg() {
		return msg;
	}// getMsg()

	uint32_t custom_exception::getCode() {
		return code;
	}// getCode()

	void arg_function( int argc, const char* argv[] ) {
		for ( int i = 0; i < argc; i++ ) {
			if ( std::string( argv[1] ) == "--help" || std::string( argv[1] ) == "-h" ) {
				std::cout << "-a, --arg <---- показать передаваемые аргументы\n-h, --help <---- показать список команд\n";
				exit( 0 );
			}
			if ( std::string( argv[i] ) == "--arg" || std::string( argv[i] ) == "-a" ) {
				std::cout << "\ninput arguments when running the " << argv[0] << ": " << argc << "\n\n";
				for ( int j = 0; j < argc; j++ ) {
					std::cout << "argument " << j << ": " << argv[j] << "\n";
				}
				std::cout << "\n";
			}
		}
	}// arg_foo()

	void log_save( std::string& path, std::string& text, std::chrono::duration<float> program_time ) {
		std::ofstream fout;
		fout.open( path );

		if ( !fout.is_open() ) {
			throw std::runtime_error( "failed to save log!" );
		} else {
			fout << "----------LOG-FILE------------\n";
			fout <<	"\"custom message start\"\n";
			fout << text;
			fout << "\n\"custom message end\"\n";
			fout <<	"----------DATE--------\n";
			
			std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			
			fout << std::ctime(&now_time);
			fout << "program time: " << program_time << "\n";
			fout << "----------END-FILE------------\n";
		}
		fout.close();
	}// log_save()

	void error_log_save( std::string& path, std::string& text, std::string& error_text, std::chrono::duration<float> program_time ) {
		std::ofstream fout;
		fout.open( path );

		if ( !fout.is_open() ) {
			throw std::runtime_error( "failed to save log!" );
		} else {
			fout << "----------LOG-FILE------------\n";
			fout <<	"\"custom message start\"\n";
			fout << text;
			fout << "\n\"custom message end\"\n";
			fout <<	"----------DATE--------\n";
			std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

			fout << std::ctime(&now_time);
			fout <<	"--------ERROR---------\n";
			fout << error_text << "\n";
			fout <<	"----------------------\n";
			fout << "program time: " << program_time << "\n";
			fout << "----------END-FILE------------\n";
		}
		fout.close();
	}// error_log_save()

	std::chrono::time_point<std::chrono::high_resolution_clock> timer_start() {
		std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
		return start;
	}// timer_start()

	std::chrono::duration<float> timer_end( std::chrono::time_point<std::chrono::high_resolution_clock>& start ) {
		std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		return duration;
	}// timer_end()
}// namespace su ( special utils )
