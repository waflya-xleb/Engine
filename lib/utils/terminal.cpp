#include "terminal.hpp"

namespace su {
	void terminal() {
		std::vector< std::string > arguments;
		std::string str = "";
		std::string buffer = "";
		std::string cli_user_name = "user";
		while( true ) {

			std::cout << MAGNETA << cli_user_name << RESET << "@" << BLUE << "terminal: " << CYAN;
			std::getline(std::cin, str);
			str += " ";
			//std::cin >> str;

			for ( int i = 0; i < str.size(); i++ ) {
				if ( str[i] == ' ' && buffer != ""  ) {
					arguments.push_back( buffer );
					buffer = "";
				}
				if ( str[i] == ' ' ) {
					continue;
				}
				buffer += str[i];
			}

			if ( arguments.empty() ) {
				arguments.push_back( "" );
			}

			//for ( int i = 0; i < arguments.size(); i++ ) {
			//	std::cout << MAGNETA << arguments[i] << RESET << "\n";
			//}

			if ( arguments[0] == "mkdir" ) {
				if ( arguments.size() >= 2 ) {
					if ( mkdir( arguments[1].c_str(), 0777) == 0 ) {
						std::cout << GREEN << "new directory created successfully!\n";
					} else {
						std::cout << YELLOW << "failed to create new directory.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "rmdir" ) {
				if ( arguments.size() >= 2 ) {
					if ( rmdir( arguments[1].c_str() ) == 0 ) {
						std::cout << GREEN << "directory remove successfully!\n";
					} else {
						std::cout << YELLOW << "failed to remove directory.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "cd" ) {
				if ( arguments.size() >= 2 ) {
					if ( chdir( arguments[1].c_str() ) == 0 ) {
						std::cout << GREEN << "directory change\n";
					} else {
						std::cout << YELLOW << "failed to change directory.\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "ls" ) {
				std::cout << YELLOW << "\r" << std::flush;
				system("dir");
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "clear" || arguments[0] == "cls" ) {
				system("clear");
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "echo" ) {
				if ( arguments.size() >= 2 ) {
					for ( int i = 1; i < arguments.size(); i++ ) {
						std::cout << RESET << arguments[i] << "\n";
					}
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "set" ) {
				if ( arguments.size() >= 3 && arguments[1] == "userName" ) {
					cli_user_name = arguments[2];
				}
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";

			} else if ( arguments[0] == "exit" ) {
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";
				break;

			} else if ( arguments[0] == "" ) {
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";
				continue;

			} else {
				std::cout << "unknown command\n";
				arguments.erase( arguments.begin(), arguments.end() );
				arguments[0] = "";
			}
		}// while
	}// terminal()
}
