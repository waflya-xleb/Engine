#include "vk.hpp"

bool Vulkan::run( su::warning_struct &warning_list ) {
	try {
		if ( createInstance( warning_list ) ) {
			warning_list.warning_L2.push_back( "function 'createInstance' in 'vk_interface' library failure. --- run.cpp" );
			return 1;
		}
		return 0;
	} catch(...) {
		warning_list.warning_L2.push_back( "unknown error in function 'run' in 'vk_interface' library. --- run.cpp" );
		return 1;
	}
}
