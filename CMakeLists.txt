cmake_minimum_required ( VERSION 3.31.6 )

message ( "Starting compiling project..." )

include ( base-kit.cmake )

project(
	Project_Engine
	VERSION ${ver}
	DESCRIPTION "just engine."
	LANGUAGES ${supported_languages})

#add_subdirectory( lib/utils utils )
add_subdirectory( ../../utils utils )
#add_subdirectory( lib/vk_interface vk_interface )
add_subdirectory( ../../vk_interface vk_interface )
add_subdirectory( src )
