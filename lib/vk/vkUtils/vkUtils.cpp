#include "vkUtils.hpp"

namespace vk {
	namespace su {
		bool checkValidationLayerSupport( std::vector< const char* > requestedLayers, std::vector< const char* > &unavailableLayers ) {
			
			bool layerAvailable;

			uint32_t layerCount;
			vkEnumerateInstanceLayerProperties( &layerCount, nullptr );
			
			std::vector < VkLayerProperties > availableLayers( layerCount );
			vkEnumerateInstanceLayerProperties( &layerCount, availableLayers.data() );

			for ( const char* layerName : requestedLayers ) {
				layerAvailable = false;

				for ( const VkLayerProperties& layerProperties : availableLayers ) {
					
					if ( strcmp( layerName, layerProperties.layerName ) == 0 ) {
						layerAvailable = true;
						break;
					}
				}

				if ( !layerAvailable ) {
					unavailableLayers.push_back( layerName );
				}
			}

			return unavailableLayers.size() == 0;
		}
	}// su namespace
}// vk namespace
