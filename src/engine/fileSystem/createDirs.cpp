#include "../engine.hpp"

bool Engine::createDirs() {
	bool is_normal = 0;
	mkdir( "logs", 0777) == 0 ? std::cout << GREEN << "'logs' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'logs' dir\n" << RESET;
	mkdir( "scripts", 0777) == 0 ? std::cout << GREEN << "'scripts' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'scripts' dir\n" << RESET;
	mkdir( "temp", 0777) == 0 ? std::cout << GREEN << "'temp' dir create success!\n" << RESET : std::cout << YELLOW << "failed to create 'temp' dir\n" << RESET;
	return 0;
}
