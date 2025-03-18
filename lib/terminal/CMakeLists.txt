cmake_minimum_required ( VERSION 3.31.6 )

message ( "Starting compiling terminal..." )

set ( CMAKE_CXX_STANDARD 23 )

project( terminal
	VERSION 0.0.2
	LANGUAGES CXX )

add_library( ${PROJECT_NAME} SHARED terminal.cpp )
add_library( utils::terminal ALIAS ${PROJECT_NAME} )
