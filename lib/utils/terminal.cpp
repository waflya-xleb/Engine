#include "terminal.hpp"

namespace su {
	command_list switch_str (std::string const& input_string) {
		if ( input_string == "ls" || input_string == "clear" || input_string == "cls" || input_string == "cd" || input_string == "mkdir" || input_string == "rmdir" || input_string == "set user name" || input_string == "exit" ) {
    			if (input_string == "ls") return ls;
    			if (input_string == "clear" || input_string == "cls") return clear;
    			if (input_string == "cd") return cd;
    			if (input_string == "mkdir") return _mkdir;
    			if (input_string == "rmdir") return _rmdir;
    			if (input_string == "set user name") return userName;
    			if (input_string == "exit") return _exit_cli;
		} else {
			return unknown;
		}
	}// switch_str
	void terminal() {
		std::string str = "";
		std::string cli_user_name = "user";
		bool if_while_cli = true;

		while( if_while_cli ) {

			std::cout << MAGNETA << cli_user_name << RESET << "@" << BLUE << "terminal: " << KCYN;
			std::getline(std::cin, str);

			switch ( switch_str( str ) ) {
				case ls:
					system("dir");
					break;


				case clear:
					system("clear");
					break;

				case cd:
					std::cout << RESET << "input path: " << KCYN;
					std::getline(std::cin, str);
					if ( chdir( str.c_str() ) == 0 ) {
						std::cout << FGRN( "directory change\n" );
					} else {
						std::cout << FYEL( "failed to change directory.\n" );
					}
					break;

				case _mkdir:
					std::cout << RESET << "input directory name: " << KCYN;
					std::getline(std::cin, str);
					if ( mkdir( str.c_str(), 0777) == 0 ) {
						std::cout << FGRN( "new directory created successfully!\n" );
					} else {
						std::cout << FYEL( "failed to create new directory.\n" );
					}
					break;

				case _rmdir:
					std::cout << RESET << "input directory name: " << KCYN;
					std::getline(std::cin, str);
					if ( rmdir( str.c_str() ) == 0 ) {
						std::cout << FGRN( "directory remove successfully!\n" );
					} else {
						std::cout << FYEL( "failed to remove directory.\n" );
					}
					break;
				
				case userName:
					std::cout << RESET << "input user name: " << KCYN;
					std::getline(std::cin, cli_user_name);
					break;

				case _exit_cli:
					if_while_cli = false;
					break;

				case unknown:
					break;
				default:
					break;

			}// switch
		}// while
	}// terminal()
}
