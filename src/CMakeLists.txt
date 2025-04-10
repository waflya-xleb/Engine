include ( ../base-kit.cmake )

set ( EXECUTABLE-NAME "program_v-${PROJECT_VERSION}" )

#include_directories( ../lib )
include_directories( ../../../ )

add_executable( ${EXECUTABLE-NAME} main.cpp temporary.cpp )
add_executable( ${EXECUTABLE-NAME}_static main.cpp temporary.cpp )
add_executable( test_2_program main_2_test.cpp )
add_executable( test_3_program main_2_test.cpp )
add_executable( program_starter main24.c )


set ( E engine )
set ( W window )
set ( G graphics )
set ( FS fileSystem )
set ( R running )
add_library( engine SHARED ${E}/engine.cpp
	${E}/${W}/createWindow.cpp
	${E}/${G}/initVulkan.cpp
	${E}/${FS}/createDirs.cpp
	${E}/${R}/mainloop.cpp )
add_library( engine::engine ALIAS engine )
target_link_libraries( engine PUBLIC vk::vk_interface utils::utils )
set_target_properties( engine PROPERTIES
	PREFIX ""
	OUTPUT_NAME "engine"
	SUFFIX ".so"
)


add_library( static_engine STATIC ${E}/engine.cpp
	${E}/${W}/createWindow.cpp
	${E}/${G}/initVulkan.cpp
	${E}/${FS}/createDirs.cpp
	${E}/${R}/mainloop.cpp )
add_library( engine::static_engine ALIAS static_engine )
target_link_libraries( static_engine PUBLIC vk::static_vk_interface utils::static_utils )
set_target_properties( static_engine PROPERTIES
	PREFIX "static_"
	OUTPUT_NAME "engine"
	SUFFIX ".a"
)


add_library( test SHARED test.c )
set_target_properties( test PROPERTIES
	PREFIX ""
	OUTPUT_NAME "test"
	SUFFIX ".so"
)
add_library( test_static STATIC test.c )
set_target_properties( test_static PROPERTIES
	PREFIX "static_"
	OUTPUT_NAME "test"
	SUFFIX ".a"
)


target_link_libraries( ${EXECUTABLE-NAME} PRIVATE test engine::engine )
target_link_libraries( ${EXECUTABLE-NAME}_static PRIVATE test_static engine::static_engine )
target_link_libraries( test_2_program PRIVATE utils::terminal )


#message( STATUS "Project version: " ${${PROJECT}_VERSION} )
message ( "\n------------------------------\n" )
message ( "PROJECT NAME: ${PROJECT_NAME}\nPROJECT VERSION: ${PROJECT_VERSION}\nPROJECT DESCRIPTION: ${PROJECT_DESCRIPTION}\nPROJECT SUPPORTED LANGUAGES: ${supported_languages}\n" )
message ( "EXECUTABLE-NAME: ${EXECUTABLE-NAME}\nLIBS: vk::vk_interface\nSUB LIBS:\ntest SHARED test.c\n" )
message ( "------------------------------\n" )
