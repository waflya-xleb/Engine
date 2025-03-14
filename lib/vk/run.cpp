#include "vk.hpp"

void Vulkan::run() {
	try {
		createInstance();
		createPhysicalDevice();

	} catch( su::custom_exception& ex ) {
#ifdef VK_DEBUG_L1_
		std::cout << YELLOW << "error in Vulkan::run()\n";
		std::cout << "\tsu::custom_exception\n";
		std::cout << "\ttype: " << ex.getType() << "\n";
		std::cout << "\tmsg: " << ex.getMsg() << "\n";
		std::cout << "\tcode: " << ex.getCode() << "\n" << RESET;
#endif
	} catch( std::exception& ex ) {
		throw std::runtime_error( ex.what() );
	} catch(...) {
		throw std::runtime_error("unknown error.\n");
	}
}
