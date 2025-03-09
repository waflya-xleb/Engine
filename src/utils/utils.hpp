#pragma once
#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "integrated_cxx_libs.hpp"
#include "colors.hpp"

namespace su {
	class custom_exception {
		public:
			custom_exception( std::string type, std::string msg, uint32_t code );
			std::string getType();
			std::string getMsg();
			uint32_t getCode();
		private:
			std::string type;
			std::string msg;
			uint32_t code;
	};

	void arg_function( int argc, const char* argv[] );

	void log_save( std::string& path, std::string& text, std::string& error_text, std::chrono::duration<float> program_time );

	std::chrono::time_point<std::chrono::high_resolution_clock> timer_start();

	std::chrono::duration<float> timer_end( std::chrono::time_point<std::chrono::high_resolution_clock>& start );
}// namespace su ( special utils )

#endif
