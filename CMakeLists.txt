cmake_minimum_required ( VERSION 3.31.5 )

message ( "Starting compiling project..." )

include ( base-kit.cmake )

project(
	Project_Engine
	VERSION ${ver}
	LANGUAGES ${supported_languages})


add_subdirectory( src )
