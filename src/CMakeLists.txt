include ( ../base-kit.cmake )

set ( EXECUTABLE-NAME "program_v-${PROJECT_VERSION}" )

#include_directories( ../lib )
include_directories( ../../../ )

add_executable( ${EXECUTABLE-NAME} main.cpp temporary.cpp )
add_executable( test_2_program main_2_test.cpp )
add_executable( test_3_program main_2_test.cpp )
add_executable( program_starter main24.c )

add_library( engine SHARED engine/engine.cpp engine/window/createWindow.cpp )
set_target_properties( engine PROPERTIES
	PREFIX ""
	OUTPUT_NAME "engine"
	SUFFIX ".so"
)

add_library( test SHARED test.c )
set_target_properties( test PROPERTIES
	PREFIX ""
	OUTPUT_NAME "test"
	SUFFIX ".so"
)


target_link_libraries( ${EXECUTABLE-NAME} PRIVATE vk::vk_interface test engine )
target_link_libraries( test_2_program PRIVATE utils::terminal )


#message( STATUS "Project version: " ${${PROJECT}_VERSION} )
message ( "\n------------------------------\n" )
message ( "PROJECT NAME: ${PROJECT_NAME}\nPROJECT VERSION: ${PROJECT_VERSION}\nPROJECT DESCRIPTION: ${PROJECT_DESCRIPTION}\nPROJECT SUPPORTED LANGUAGES: ${supported_languages}\n" )
message ( "EXECUTABLE-NAME: ${EXECUTABLE-NAME}\nLIBS: vk::vk_interface\nSUB LIBS:\ntest SHARED test.c\n" )
message ( "------------------------------\n" )
